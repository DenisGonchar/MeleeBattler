#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MBAttackAbility.generated.h"

class UMBComboAttackComponent;
class AMBBaseCharacter;


UCLASS()
class UMBAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

protected:
	UPROPERTY(EditAnywhere)
	float ComboAttackInterval = 0.1;

	UPROPERTY(EditAnywhere)
	FGameplayTagContainer ComboAbilityAttackTegs;
	
private:
	void UseAttack();

	TWeakObjectPtr<UMBComboAttackComponent> ComboAttackComponent;

	FTimerHandle AttackTimer;
};
