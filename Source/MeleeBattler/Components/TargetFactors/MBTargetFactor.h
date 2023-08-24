// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MBTargetFactor.generated.h"

UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced)
class  UMBTargetFactor : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	float GetPriority(AActor* TestActor) const;
	
	UFUNCTION(BlueprintNativeEvent)
	TArray<AActor*> GetHighPriorityActors(const TArray<AActor*>& TestActors ) const;
	
};
