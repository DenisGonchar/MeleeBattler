// Fill out your copyright notice in the Description page of Project Settings.


#include "MBComboAttackComponent.h"

#include "MBEquipComponent.h"
#include "Data/MBComboAttackData.h"
#include "Items/MBMeleeItem.h"
#include "Powns/BaseCharacter/MBBaseCharacter.h"


UMBComboAttackComponent::UMBComboAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}
void UMBComboAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	OwningCharacter = GetOwner<AMBBaseCharacter>();
	if (OwningCharacter.IsValid())
	{
		EquipComponent = OwningCharacter->GetEquipComponent();
	}
	
}

void UMBComboAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UMBComboAttackComponent::Attack()
{
	const auto activeItem = GetActiveItem();
	if ( !OwningCharacter.IsValid() || activeItem == nullptr || activeItem->ComboAttackData == nullptr || activeItem->ComboAttackData->ComboAbilities.Num() == 0)
	{
		return;
	}

	const auto comboAttackData = activeItem->ComboAttackData;
	OwningCharacter->UseAbility(comboAttackData->ComboAbilities[0]);
		
}

AMBMeleeItem* UMBComboAttackComponent::GetActiveItem() const
{
	if (EquipComponent.IsValid())
	{
		return EquipComponent->GetActiveItem();
	}
	
	return  nullptr;
}

