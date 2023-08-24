// Fill out your copyright notice in the Description page of Project Settings.


#include "MBTargetFactor.h"

float UMBTargetFactor::GetPriority_Implementation(AActor* TestActor) const
{
	return 0.f;
}

TArray<AActor*> UMBTargetFactor::GetHighPriorityActors_Implementation(const TArray<AActor*>& TestActors) const
{
	return {};
}
