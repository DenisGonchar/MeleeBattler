// Fill out your copyright notice in the Description page of Project Settings.


#include "MBAbilityRadialTargetActor.h"

#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"


AMBAbilityRadialTargetActor::AMBAbilityRadialTargetActor()
{
	bDestroyOnConfirmation = false;
	ShouldProduceTargetDataOnServer = true;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	
}

void AMBAbilityRadialTargetActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float sectorStartAngle = 0.0f;
	float sectorEndAngle = 0.0f;
	
	for (auto itKey = TraceCurve->FloatCurve.GetKeyIterator(); itKey; ++itKey)
	{
		if (itKey->Time <= TraceTickTime)
		{
			sectorStartAngle = itKey->Value;
		}
		else
		{
			sectorEndAngle = itKey->Value;
			break;
		}
	}

	const FVector sourceLocation = StartLocation.GetTargetingTransform().GetLocation();
	const FRotator sourceRotation = StartLocation.GetTargetingTransform().Rotator();
	
	const FVector traceStart = sourceLocation;
	const FVector traceEnd = traceStart + FVector::OneVector;

	const EDrawDebugTrace::Type traceDubug = bDebug ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None;
	TArray<FHitResult> HitResults;
	
	UKismetSystemLibrary::SphereTraceMulti(this, traceStart, traceEnd, TraceDistance, TraceChannel,
		false, HittedActors, traceDubug,  HitResults, true);

	FGameplayAbilityTargetDataHandle TargetDataHandle;
	for (const auto& hitResult : HitResults)
	{
		//const auto hitActor = hitResult.GetActor();
		//if (Filter.FilterPassesForActor(hitActor))
		if(const auto hitActor = hitResult.GetActor())
		{
			FVector hitActorLocationTest = hitActor->GetActorLocation();
			hitActorLocationTest.Z = sourceLocation.Z;
			FVector sourceToTargetDirection = (hitActorLocationTest - sourceLocation).GetSafeNormal();
			
			const float centerSectorAngle = sectorStartAngle + (sectorEndAngle - sectorStartAngle) / 2; 
			FVector sectorDirection = (sourceRotation + FRotator(0.0f, centerSectorAngle, 0.0f)).Vector();

			if (bDebugSector)
			{
				DrawDebugLine(GetWorld(), traceStart, sourceLocation + sourceToTargetDirection * (TraceDistance * 2), FColor::Yellow, false, 0.f, 1, 5.0f);
				DrawDebugLine(GetWorld(), traceStart, sourceLocation + sectorDirection * (TraceDistance * 2), FColor::Yellow, false, 0.f, 1, 5.0f);

			}

			const float andgleBetweenTargetAndSector = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(sourceToTargetDirection, sectorDirection)));
			const float halfSectorAngle = FMath::Abs(sectorEndAngle - sectorStartAngle) / 2;
			if (andgleBetweenTargetAndSector <= halfSectorAngle)
			{
				FGameplayAbilityTargetData_SingleTargetHit* singleTargetData = new FGameplayAbilityTargetData_SingleTargetHit();
				singleTargetData->HitResult = hitResult;
				TargetDataHandle.Add(singleTargetData);

				HittedActors.Add(hitActor);
			}
		}
	}

	if (bDebugSector)
	{
		const float drawTime = 1.5f;
		
		const FVector sectorStart = traceStart;
		const FVector sectorStartDirection = (StartLocation.GetTargetingTransform().Rotator() + FRotator(0.0f, sectorStartAngle, 0.0f)).Vector();
		const FVector sectorEndDirection = (StartLocation.GetTargetingTransform().Rotator() + FRotator(0.0f, sectorEndAngle, 0.0f)).Vector();

		DrawDebugLine(GetWorld(), traceStart, sectorStart + sectorStartDirection * TraceDistance, FColor::Green, false, drawTime);
		DrawDebugLine(GetWorld(), traceStart, sectorStart + sectorEndDirection * TraceDistance, FColor::Green, false, drawTime  );
		
	}
	
	TraceTickTime += DeltaSeconds;
	
	if (TargetDataHandle.Num() > 0)
	{
		TargetDataReadyDelegate.Broadcast(TargetDataHandle);
	}
	
	if (TraceTickTime > TraceCurve->FloatCurve.Keys.Last().Time)
	{
		Destroy();
	}
	
}

void AMBAbilityRadialTargetActor::StartTargeting(UGameplayAbility* Ability)
{
	Super::StartTargeting(Ability);

	if (TraceCurve->FloatCurve.Keys.Num() <= 2)
	{
		Destroy();
	}
	else
	{
		SetActorTickEnabled(true);

	}
	
}

void AMBAbilityRadialTargetActor::ConfirmTargeting()
{
	Super::ConfirmTargeting();

}

bool AMBAbilityRadialTargetActor::IsConfirmTargetingAllowed()
{
	return false;
}
