#include "UI/AttributesWidget.h"

#include "GAS/MCAttributeSet.h"
#include "MainCharacter.h"

void UAttributesWidget::BindToAttributes()
{
	const AMainCharacter* MainCharacter = Cast<AMainCharacter>(GetOwningPlayerPawn());
	if (!MainCharacter) return;

	UAbilitySystemComponent* ASC = MainCharacter->GetAbilitySystemComponent();
	const UMCAttributeSet* AttributeSet = MainCharacter->GetAttributeSet();

	HealthPercent = NUMERIC_VALUE(AttributeSet, Health) / NUMERIC_VALUE(AttributeSet, MaxHealth);
	StaminaPercent = NUMERIC_VALUE(AttributeSet, Stamina) / NUMERIC_VALUE(AttributeSet, MaxStamina);

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
		{
			HealthPercent = Data.NewValue / NUMERIC_VALUE(AttributeSet, MaxHealth);
		}
	);

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStaminaAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
		{
			StaminaPercent = Data.NewValue / NUMERIC_VALUE(AttributeSet, MaxStamina);
		}
	);
}
