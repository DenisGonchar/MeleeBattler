// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MBTargetFactor.h"
#include "MBViewTargetFactor.generated.h"


UCLASS()
class MELEEBATTLER_API UMBViewTargetFactor : public UMBTargetFactor
{
	GENERATED_BODY()

public:

	virtual TArray<AActor*> GetHighPriorityActors_Implementation(const TArray<AActor*>& TestActors, bool bEnableDebug = false, float TargetRadius = 300.0f) const override;

public:
	UPROPERTY(EditAnywhere)
	float MaxViewAngle = 120.f;
};
