// Fill out your copyright notice in the Description page of Project Settings.


#include "MBMeleeItem.h"

AMBMeleeItem::AMBMeleeItem()
{
	PrimaryActorTick.bCanEverTick = true;

	TransformComponent = CreateDefaultSubobject<USceneComponent>("TransformComponent");
	SetRootComponent(TransformComponent);

	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(TransformComponent);

}

void AMBMeleeItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMBMeleeItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

