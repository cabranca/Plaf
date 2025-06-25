#include "CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "GAS/MCAttributeSet.h"
#include "GameplayEffect.h"


ACharacterBase::ACharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
    AttributeSet = CreateDefaultSubobject<UMCAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UMCAttributeSet* ACharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ACharacterBase::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	if(!HasAuthority()) return;
	
	for(TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void ACharacterBase::InitDefaultAttributes() const
{
	if(!AbilitySystemComponent || !DefaultAttributeEffect) { return; }
	
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if(SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());			
	}
}