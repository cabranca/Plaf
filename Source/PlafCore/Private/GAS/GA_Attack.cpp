#include "GAS/GA_Attack.h"

#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "GAS/MCAbilityInputID.h"
#include "Log.h"

UGA_Attack::UGA_Attack()
{
    InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGA_Attack::ActivateAbility(
    const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo,
    const FGameplayAbilityActivationInfo ActivationInfo,
    const FGameplayEventData* TriggerEventData
)
{
    if (!CommitAbility(Handle, ActorInfo, ActivationInfo))  // Gastar coste si lo tuviera
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, true);
        return;
    }

    ACharacter* Character = Cast<ACharacter>(ActorInfo->AvatarActor.Get());
    if (Character && AttackMontage)
    {
        UE_LOG(LogPlafCore, Log, TEXT("PlayingMontage"));
        Character->PlayAnimMontage(AttackMontage);
    }

    // En un caso real esperarías una notify o timer para aplicar el daño
    // pero para simplificar, terminamos la habilidad inmediatamente
    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}