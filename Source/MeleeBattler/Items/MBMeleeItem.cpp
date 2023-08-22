// Fill out your copyright notice in the Description page of Project Settings.


#include "MBMeleeItem.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Data/MBComboAttackData.h"

AMBMeleeItem::AMBMeleeItem()
{
	PrimaryActorTick.bCanEverTick = true;

	TransformComponent = CreateDefaultSubobject<USceneComponent>("TransformComponent");
	SetRootComponent(TransformComponent);

	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(TransformComponent);

}

void AMBMeleeItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMBMeleeItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMBMeleeItem::GrantAbilitiesToActor(AActor* Actor)
{
	Super::GrantAbilitiesToActor(Actor);

	if(ComboAttackData != nullptr)
	{
		if (const auto abilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor))
		{
			for (const auto ability : ComboAttackData->ComboAbilities)
			{
				//TODO remove abilityon unequip item
				abilitySystemComponent->GiveAbility(FGameplayAbilitySpec(ability));
			}
			
		}
	}
}

