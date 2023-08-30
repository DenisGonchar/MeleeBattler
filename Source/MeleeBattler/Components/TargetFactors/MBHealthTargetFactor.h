// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MBTargetFactor.h"
#include "UObject/Object.h"
#include "MBHealthTargetFactor.generated.h"

UCLASS()
class MELEEBATTLER_API UMBHealthTargetFactor : public UMBTargetFactor
{
	GENERATED_BODY()
public:
	virtual TArray<AActor*> GetHighPriorityActors_Implementation(const TArray<AActor*>& TestActors, bool bEnableDebug, float TargetRadius) const override;

	
};
