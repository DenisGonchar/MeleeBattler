// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MBBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UMBCharacterMovementComponent;
class UMBComboAttackComponent;
class UMBEquipComponent;
class UMBAttackAbility;
class UMBCharacterAttributeSet;

UCLASS(config=Game)
class AMBBaseCharacter : public ACharacter, public IAbilitySystemInterface
{

	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AMBBaseCharacter(const FObjectInitializer& ObjectInitializer);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; };
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void MoveForward(float Value);
	virtual void MoveRight(float Value);
	virtual void Turn(float Value);
	virtual void LookUp(float Value);

	virtual bool CanJumpInternal_Implementation() const override;
	virtual void OnJumped_Implementation() override;

	//Ability
	UFUNCTION(BlueprintCallable)
	void UseAbility(TSubclassOf<UGameplayAbility> Ability);
	
	//Attack
	UFUNCTION(BlueprintCallable)
	void StartAttack();

	UFUNCTION(BlueprintCallable)
	void StopAttack();
	
	UFUNCTION(BlueprintPure)
	bool CanAttack() const;
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMBAttackAbility> AttackAbility;

	
	UMBEquipComponent* GetEquipComponent() const { return  CharacterEquipComponent; };
	UMBComboAttackComponent* GetComboAttackComponent() const { return CharacterComboAttackComponent; };
	FORCEINLINE UMBCharacterMovementComponent* GetBaseCharacterMovementComponent() const { return BaseCharacterMovementComponent;}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBCharacterAttributeSet* CharacterAttributeSet;
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBEquipComponent* CharacterEquipComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBComboAttackComponent* CharacterComboAttackComponent;

	UMBCharacterMovementComponent* BaseCharacterMovementComponent;

};

