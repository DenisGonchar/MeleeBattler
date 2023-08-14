// Fill out your copyright notice in the Description page of Project Settings.


#include "MBCharacterMovementComponent.h"

#include "Powns/BaseCharacter/MBBaseCharacter.h"

void UMBCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	BaseCharacterOwner = Cast<AMBBaseCharacter>(GetOwner());
	
}


