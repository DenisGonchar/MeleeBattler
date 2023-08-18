// Fill out your copyright notice in the Description page of Project Settings.


#include "MBEquipComponent.h"

#include "GameFramework/Character.h"
#include "Items/MBMeleeItem.h"

UMBEquipComponent::UMBEquipComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMBEquipComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMBEquipComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UMBEquipComponent::EquipItemClassToHand(TSubclassOf<AMBMeleeItem> NewItem)
{
	if (NewItem != nullptr)
	{
		FActorSpawnParameters spawnParameters;
		spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		const auto itemInstance = GetWorld()->SpawnActor<AMBMeleeItem>(NewItem, spawnParameters);

		EquipItemToHand(itemInstance);
	}
}

void UMBEquipComponent::EquipItemToHand(AMBMeleeItem* NewItem)
{
	if (NewItem != nullptr)
	{
		if (ActiveItem != nullptr)
		{
			ActiveItem->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
			ActiveItem->Destroy();
		}
		
		ActiveItem = NewItem;
		const auto meshComponent = GetOwner<ACharacter>()->GetMesh();
		ActiveItem->AttachToComponent(meshComponent, FAttachmentTransformRules::SnapToTargetIncludingScale, HandItemAttachSocketName);
		
	}
}

