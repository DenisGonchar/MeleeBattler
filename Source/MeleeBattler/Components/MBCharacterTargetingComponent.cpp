// Fill out your copyright notice in the Description page of Project Settings.


#include "MBCharacterTargetingComponent.h"

UMBCHaracterTargetingComponent::UMBCHaracterTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UMBCHaracterTargetingComponent::BeginPlay()
{
	Super::BeginPlay();


}


void UMBCHaracterTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

