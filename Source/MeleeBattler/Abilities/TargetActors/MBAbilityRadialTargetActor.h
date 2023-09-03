// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "MBAbilityRadialTargetActor.generated.h"

UCLASS()
class MELEEBATTLER_API AMBAbilityRadialTargetActor : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	AMBAbilityRadialTargetActor();

	virtual void Tick(float DeltaSeconds) override;
	
	virtual void StartTargeting(UGameplayAbility* Ability) override;

	virtual void ConfirmTargeting() override;
	virtual bool IsConfirmTargetingAllowed() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn = "true"))
	float TraceDistance = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn = "true"))
	TEnumAsByte<ETraceTypeQuery> TraceChannel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn = "true"))
	class UCurveFloat* TraceCurve = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ExposeOnSpawn = "true"))
	bool bDebugSector = false;

private:
	UPROPERTY()
	TArray<AActor*>	HittedActors;

	float TraceTickTime = 0.0f;
};
