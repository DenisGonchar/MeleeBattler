#pragma once

#include "CoreMinimal.h"
#include "MBItem.h"
#include "GameFramework/Actor.h"
#include "MBMeleeItem.generated.h"

class USkeletalMeshComponent;
class UMBComboAttackData;

UCLASS(Abstract)
class MELEEBATTLER_API AMBMeleeItem : public AMBItem
{
	GENERATED_BODY()

public:
	AMBMeleeItem();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo Attack")
	UMBComboAttackData* ComboAttackData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equip")
	FName AttachSosketName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* TransformComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* MeshComponent;

	
};
