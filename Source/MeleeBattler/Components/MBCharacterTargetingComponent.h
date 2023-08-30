#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetFactors/MBTargetFactor.h"
#include "MBCharacterTargetingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MELEEBATTLER_API UMBCharacterTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMBCharacterTargetingComponent();

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	AActor* GetTarget() const;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool BIsEnableDebug = false;

protected:
	void DrawDebug();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxTargetRadius = 300.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TEnumAsByte<ETraceTypeQuery> TraceType;
	
	UPROPERTY(EditAnywhere,Instanced)
	TArray<UMBTargetFactor*> TargetFactors;
	
};
