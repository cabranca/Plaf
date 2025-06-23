#pragma once

#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MCAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class UMCAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UMCAttributeSet, Health)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes|Health")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UMCAttributeSet, MaxHealth)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina")
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UMCAttributeSet, Stamina)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes|Stamina")
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UMCAttributeSet, MaxStamina)

    UPROPERTY(BlueprintReadOnly, Category = "Attributes|Combat")
    FGameplayAttributeData AttackPower;
    ATTRIBUTE_ACCESSORS(UMCAttributeSet, AttackPower)
};