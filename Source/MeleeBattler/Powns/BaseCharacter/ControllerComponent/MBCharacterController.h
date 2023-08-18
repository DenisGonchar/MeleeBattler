// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MBCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class MELEEBATTLER_API AMBCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;

private:
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);

	void Jump();

	void Attack();
	
	TSoftObjectPtr<class AMBBaseCharacter> CachedBaseCharacter;

};
