// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "MBAbilityTask_RotateToActor.generated.h"

class AActor;

UCLASS()
class MELEEBATTLER_API UMBAbilityTask_RotateToActor : public UAbilityTask
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTaskDelegate);

public:
	UMBAbilityTask_RotateToActor();
	
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UMBAbilityTask_RotateToActor* RotateToActor(UGameplayAbility* OwningAbility,	AActor* TargetActor, float RotationSpeed);
	
	virtual void Activate() override;
	
	virtual void TickTask(float DeltaTime) override;

public:
	UPROPERTY(BlueprintAssignable)
	FTaskDelegate OnFinish;

	
private:
	
	TWeakObjectPtr<AActor> TargetActor;

	float RotationSpeed;
};
