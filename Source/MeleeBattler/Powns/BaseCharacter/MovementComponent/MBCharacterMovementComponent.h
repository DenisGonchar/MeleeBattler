// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MBCharacterMovementComponent.generated.h"


class AMBBaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MELEEBATTLER_API UMBCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

protected:
	AMBBaseCharacter* BaseCharacterOwner;

	AMBBaseCharacter* GetBaseCharacterOwner() const { return  StaticCast<AMBBaseCharacter*>(BaseCharacterOwner); };
};
