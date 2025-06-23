#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "MainCharacter.generated.h"

/***FORWARD DECLARATIONS***/
class USpringArmComponent;
class UCameraComponent;
class UAbilitySystemComponent;
class UMCAttributeSet;
class UGameplayAbility;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS()
class AMainCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMainCharacter(const FObjectInitializer& ObjectInitializer); // Constructor for the Main Character.
	virtual void BeginPlay() override; // Called when the actor is spawned.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Setups the Input Actions for the Main Character.


	/***COMPONENTS***/
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") USpringArmComponent* CameraBoom; // Spring arm for the Main Character camera

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") UCameraComponent* FollowCamera; // Third Person Camera.


	/***GAS***/
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS") UAbilitySystemComponent* AbilitySystem; // Component that handles de GAS
	UPROPERTY() UMCAttributeSet* Attributes; // Set of Main Character attributes.

	UPROPERTY(EditDefaultsOnly, Category = "Abilities") TSubclassOf<UGameplayAbility> AttackAbilityClass; // Attack Gameplay Ability class.

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	/***INPUT***/
private:
	UPROPERTY(EditAnywhere, Category="Input") UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* MoveAction; // Input for character movement.
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* LookAction; // Input for camera rotation.
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* AttackAction; // Input for basic attack.
	

	void Move(const FInputActionValue& Value); // Callback for character movement.
	void Look(const FInputActionValue& Value); // Callback for camera rotation.
	void BasicAttack(const FInputActionValue& Value); // Callback for the basic attack.
};
