#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CharacterBase.h"

#include "MainCharacter.generated.h"

/***FORWARD DECLARATIONS***/
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS()
class AMainCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	AMainCharacter(); // Constructor for the Main Character.
	virtual void BeginPlay() override; // Called when the actor is spawned.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Setups the Input Actions for the Main Character.


	/***COMPONENTS***/
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") USpringArmComponent* CameraBoom; // Spring arm for the Main Character camera

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") UCameraComponent* FollowCamera; // Third Person Camera.


	/***INPUT***/
private:
	UPROPERTY(EditAnywhere, Category="Input") UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* MoveAction; // Input for character movement.
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* LookAction; // Input for camera rotation.
	UPROPERTY(EditAnywhere, Category="Input") UInputAction* AttackAction; // Input for basic attack.
	

	void Move(const FInputActionValue& Value); // Callback for character movement.
	void Look(const FInputActionValue& Value); // Callback for camera rotation.


	/***UI***/
	void InitHUD() const;
};
