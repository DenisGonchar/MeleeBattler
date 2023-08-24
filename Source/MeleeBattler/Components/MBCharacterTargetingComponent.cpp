// Fill out your copyright notice in the Description page of Project Settings.


#include "MBCharacterTargetingComponent.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Powns/BaseCharacter/MBBaseCharacter.h"
#include "TargetFactors/MBTargetFactor.h"


UMBCharacterTargetingComponent::UMBCharacterTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UMBCharacterTargetingComponent::BeginPlay()
{
	Super::BeginPlay();


}


void UMBCharacterTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                   FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (BIsEnableDebug)
	{
		DrawDebug();
	}
}


AActor* UMBCharacterTargetingComponent::GetTarget() const
{
	
	const FVector traceStart = GetOwner()->GetActorLocation();
	const FVector traceEnd = traceStart * FVector::OneVector;

	EDrawDebugTrace::Type drowDebug = BIsEnableDebug ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None;
	
	TArray<AActor*> ignoreActors = {GetOwner()};
	TArray<FHitResult> hitResults;
	
	UKismetSystemLibrary::SphereTraceMulti(this, traceStart, traceEnd, MaxTargetRadius, TraceType, false, ignoreActors,  drowDebug, hitResults, true);

	TArray<AActor*> potentialTargets;
	for (const auto& hitResult : hitResults)
	{
		if (const auto character = Cast<AMBBaseCharacter>(hitResult.GetActor()))
		{
			potentialTargets.Add(character);
		}
	}
	if (potentialTargets.Num() == 0)
	{
		return nullptr;
	}
	
	for (const auto targetFactor : TargetFactors)
	{
		if (targetFactor != nullptr)
		{
			potentialTargets = targetFactor->GetHighPriorityActors(potentialTargets);
		}
	}
	
	if (potentialTargets.Num() != 0)
	{
		
		return potentialTargets[0];
	}
	

	return nullptr;
}


void UMBCharacterTargetingComponent::DrawDebug()
{
	if (const auto target = GetTarget())
	{
		DrawDebugLine(GetWorld(),GetOwner()->GetActorLocation(), target->GetActorLocation(), FColor::Green,false);
		
	}
	
}
