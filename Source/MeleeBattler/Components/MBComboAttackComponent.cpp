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

void UMBComboAttackComponent::NextAttackAbility()
{
	const auto activeItem = GetActiveItem();
	if (LastAbilityItem == activeItem)
	{
		const auto comboAttackData = activeItem->ComboAttackData;

		LastComboAttackAbilityIndex++;
		if(!comboAttackData->ComboAbilities.IsValidIndex(LastComboAttackAbilityIndex))
		{
			LastComboAttackAbilityIndex = 0;
			
		}
	}
	else
	{
		ResetCombo();
	}
}

void UMBComboAttackComponent::ResetCombo()
{
	LastAbilityItem = GetActiveItem();
	LastComboAttackAbilityIndex = 0;
}

TSubclassOf<UGameplayAbility> UMBComboAttackComponent::GetNextComboAbility() const
{
	if (const auto activeItem = GetActiveItem())
	{
		if (const auto comboAttackData = activeItem->ComboAttackData)
		{
			if (comboAttackData->ComboAbilities.IsValidIndex(LastComboAttackAbilityIndex))
			{
				return comboAttackData->ComboAbilities[LastComboAttackAbilityIndex];
			}
		}
	}
	return  nullptr;
	
}


AMBMeleeItem* UMBComboAttackComponent::GetActiveItem() const
{
	if (EquipComponent.IsValid())
	{
		return EquipComponent->GetActiveItem();
	}
	
	return  nullptr;
}

