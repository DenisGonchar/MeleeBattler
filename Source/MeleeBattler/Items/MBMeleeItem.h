// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MBItem.h"
#include "GameFramework/Actor.h"
#include "MBMeleeItem.generated.h"

UCLASS()
class MELEEBATTLER_API AMBMeleeItem : public AMBItem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMBMeleeItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
