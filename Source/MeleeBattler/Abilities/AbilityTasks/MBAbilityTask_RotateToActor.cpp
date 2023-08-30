#include "MBAbilityTask_RotateToActor.h"

#include "Kismet/KismetMathLibrary.h"

UMBAbilityTask_RotateToActor::UMBAbilityTask_RotateToActor()
{
	bTickingTask = true;
	
}

UMBAbilityTask_RotateToActor* UMBAbilityTask_RotateToActor::RotateToActor(UGameplayAbility* OwningAbility,
                                                                          AActor* TargetActor, float RotationSpeed)
{
	UMBAbilityTask_RotateToActor* task = NewAbilityTask<UMBAbilityTask_RotateToActor>(OwningAbility);
	task->TargetActor = TargetActor;
	task->RotationSpeed = RotationSpeed;

	
	return task;
}

void UMBAbilityTask_RotateToActor::Activate()
{
	Super::Activate();

	if (!TargetActor.IsValid() || RotationSpeed <= KINDA_SMALL_NUMBER)
	{
		EndTask();
		
	}
}

void UMBAbilityTask_RotateToActor::TickTask(float DeltaTime)
{
	Super::TickTask(DeltaTime);

	if (TargetActor.IsValid())
	{
		FRotator targetRotation = UKismetMathLibrary::FindLookAtRotation(GetOwnerActor()->GetActorLocation(), TargetActor->GetActorLocation());
		FRotator resultRotation = FMath::RInterpConstantTo(GetOwnerActor()->GetActorRotation(), targetRotation, DeltaTime, RotationSpeed);
		
		GetOwnerActor()->SetActorRotation(resultRotation);
		
		if (resultRotation.Equals(targetRotation))
		{
			OnFinish.Broadcast();
			EndTask();
		}
	}
}
