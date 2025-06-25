#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "GameplayHUD.generated.h"

// Forward declarations
class UAttributesWidget;

UCLASS()
class AGameplayHUD : public AHUD
{
	GENERATED_BODY()
public:
	void Init();
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributeWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAttributesWidget> AttributeWidget;
};