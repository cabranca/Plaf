#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "AttributesWidget.generated.h"

UCLASS()
class UAttributesWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindToAttributes();

protected:
	UPROPERTY(BlueprintReadOnly) float HealthPercent; // Current Health / Max Health.
	UPROPERTY(BlueprintReadOnly) float StaminaPercent; // Current Stamina / Max Stamina.
};
