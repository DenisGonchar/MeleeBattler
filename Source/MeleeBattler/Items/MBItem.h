// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MBItem.generated.h"

UCLASS(Abstract)
class MELEEBATTLER_API AMBItem : public AActor
{
	GENERATED_BODY()

public:
	virtual  void GrantAbilitiesToActor(AActor* Actor);
};
