// Copyright Epic Games, Inc. All Rights Reserved.

#include "MBBaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/MBComboAttackComponent.h"
#include "Components/MBEquipComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "MovementComponent/MBCharacterMovementComponent.h"
#include "Abilities/MBAttackAbility.h"
#include "Abilities/GameplayAbility.h"
#include "Abilities/MBCharacterAttributeSet.h"
#include "Components/MBCharacterTargetingComponent.h"

AMBBaseCharacter::AMBBaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMBCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))

{
	BaseCharacterMovementComponent = StaticCast<UMBCharacterMovementComponent*>(GetCharacterMovement());

	//PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->TargetArmLength = 500.0f;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;
	

	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700;

	//Components
	CharacterAttributeSet = CreateDefaultSubobject<UMBCharacterAttributeSet>("CharacterAttributeSet");
	CharacterEquipComponent = CreateDefaultSubobject<UMBEquipComponent>(TEXT("EquipComponent"));
	CharacterComboAttackComponent = CreateDefaultSubobject<UMBComboAttackComponent>(TEXT("ComboAttackComponent"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	TargetingComponent = CreateDefaultSubobject<UMBCharacterTargetingComponent>("TargetingComponent");
}

void AMBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMBBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMBBaseCharacter::MoveForward(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);

	}

}

void AMBBaseCharacter::MoveRight(float Value)
{
	if ((GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, Value);

	}

}

void AMBBaseCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AMBBaseCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

bool AMBBaseCharacter::CanJumpInternal_Implementation() const
{
	return Super::CanJumpInternal_Implementation();
}

void AMBBaseCharacter::OnJumped_Implementation()
{
	Super::OnJumped_Implementation();
}

void AMBBaseCharacter::UseAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if (Ability != nullptr)
	{
		AbilitySystemComponent->TryActivateAbilityByClass(Ability);
		
	}
}

void AMBBaseCharacter::StartAttack()
{
	UseAbility(AttackAbility);
}

void AMBBaseCharacter::StopAttack()
{
	if (const auto abilitySpec = AbilitySystemComponent->FindAbilitySpecFromClass(AttackAbility))
	{
		//AbilitySystemComponent->ReplicateEndOrCancelAbility(abilitySpec->Handle, abilitySpec->ActivationInfo, abilitySpec->Ability, false);
		AbilitySystemComponent->CancelAbility(abilitySpec->Ability);
	}	
}

bool AMBBaseCharacter::CanAttack() const
{
	return CharacterEquipComponent->GetActiveItem() != nullptr;
}

