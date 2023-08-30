// Fill out your copyright notice in the Description page of Project Settings.


#include "MBViewTargetFactor.h"

#include "DrawDebugHelpers.h"

TArray<AActor*> UMBViewTargetFactor::GetHighPriorityActors_Implementation(
	const TArray<AActor*>& TestActors, bool bEnableDebug, float TargetRadius) const
{
	if (const auto actorOwner = GetTypedOuter<AActor>())
	{
		const FVector forwardVector = actorOwner->GetActorForwardVector();

		if (bEnableDebug)
		{
			FVector lineStart = actorOwner->GetActorLocation();
			const float drawDistance = TargetRadius;
			const float lineThickness = 4.f;
			
			FRotator lineViewRotator(0.f, MaxViewAngle / 2, 0.0f);
			
			const FVector rightLinDirection = lineViewRotator.RotateVector(forwardVector);
			DrawDebugLine(actorOwner->GetWorld(), lineStart, lineStart + rightLinDirection * drawDistance, FColor::Orange, false, -1.0f, 0, lineThickness);
			
			lineViewRotator.Yaw *= -1.0f;
			const FVector leftLinDirection = lineViewRotator.RotateVector(forwardVector);
			DrawDebugLine(actorOwner->GetWorld(), lineStart, lineStart + leftLinDirection * drawDistance, FColor::Orange, false, -1.0f, 0, lineThickness);

		}

		TArray<AActor*> priorityActors;
		for (const auto testActor : TestActors)
		{
			if (testActor != nullptr)
			{
				const FVector directionToTarget = (testActor->GetActorLocation() - actorOwner->GetActorLocation()).GetSafeNormal();
				
				const float angle = FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(directionToTarget, forwardVector)));

				if (angle <= MaxViewAngle / 2)
				{
					priorityActors.Add(testActor);
				}
				
			}
		}

		return priorityActors;
		
	}
	return {};
}
