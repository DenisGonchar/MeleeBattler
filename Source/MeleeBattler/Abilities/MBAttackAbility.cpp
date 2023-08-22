#include "MBAttackAbility.h"

#include "AbilitySystemComponent.h"
#include "Components/MBComboAttackComponent.h"
#include "Powns/BaseCharacter/MBBaseCharacter.h"

void UMBAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                       const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                       const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (const auto owningCharacter = Cast<AMBBaseCharacter>(ActorInfo->OwnerActor.Get()))
	{
		ComboAttackComponent = owningCharacter->GetComboAttackComponent();
	}

	if (ComboAttackComponent.IsValid())
	{
		ComboAttackComponent->ResetCombo();
		GetWorld()->GetTimerManager().SetTimer(AttackTimer, this, &UMBAttackAbility::UseAttack, ComboAttackInterval, true, 0.f);
	}

}

void UMBAttackAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	GetWorld()->GetTimerManager().ClearTimer(AttackTimer);
	
}

void UMBAttackAbility::UseAttack()
{
	const auto abilitySystem = GetAbilitySystemComponentFromActorInfo(); 
	TArray<FGameplayAbilitySpec*> comboAttackAbilities; 
	abilitySystem->GetActivatableGameplayAbilitySpecsByAllMatchingTags(ComboAbilityAttackTegs, comboAttackAbilities);

	//первый вариан поиска
	// bool bHasActiveCombo = false;
	// for(const auto abilitySpec : comboAttackAbilities)
	// {
	// 	if (abilitySpec != nullptr && abilitySpec->IsActive())
	// 	{
	// 		bHasActiveCombo = true;
	// 		break;
	// 	}
	// }

	//второй вариан поиска
	const auto activeComboAbilitySpec = Algo::FindByPredicate(comboAttackAbilities, [](const FGameplayAbilitySpec* Spec)
	{
		return Spec != nullptr && Spec->IsActive();
	});

	if (activeComboAbilitySpec == nullptr)
	{
		if (const auto comboAbility = ComboAttackComponent->GetNextComboAbility())
		{
			abilitySystem->TryActivateAbilityByClass(comboAbility);
		}
		ComboAttackComponent->NextAttackAbility();
	}
	
}
