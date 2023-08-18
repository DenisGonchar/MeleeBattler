// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MBComboAttackComponent.generated.h"


class UMBEquipComponent;
class AMBBaseCharacter;
class AMBMeleeItem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MELEEBATTLER_API UMBComboAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMBComboAttackComponent();

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Attack();

public:
	
protected:

private:
	AMBMeleeItem* GetActiveItem() const;
	
	TWeakObjectPtr<AMBBaseCharacter> OwningCharacter;
	TWeakObjectPtr<UMBEquipComponent> EquipComponent;
	
};
