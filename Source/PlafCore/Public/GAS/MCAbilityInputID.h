#pragma once

#include "CoreMinimal.h"
#include "MCAbilityInputID.generated.h"

UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
    None        UMETA(DisplayName = "None"),
    Confirm     UMETA(DisplayName = "Confirm"),
    Cancel      UMETA(DisplayName = "Cancel"),
    Attack      UMETA(DisplayName = "Attack")
};