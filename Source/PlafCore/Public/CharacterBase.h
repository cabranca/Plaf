#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "CharacterBase.generated.h"

// Forward declarations.
class UGameplayAbility;
class UMCAttributeSet;
class UGameplayEffect;

UCLASS()
class ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UMCAttributeSet* GetAttributeSet() const;

protected:
	void GiveDefaultAbilities();
	void InitDefaultAttributes() const;
		
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; // Component that handles de GAS

	UPROPERTY()
	TObjectPtr<UMCAttributeSet> AttributeSet; // Set of Main Character attributes.

	UPROPERTY(EditDefaultsOnly, Category = "GAS")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities; // Array of character abilities.
	
	UPROPERTY(EditDefaultsOnly, Category = "GAS")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;
};
