// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MBBaseCharacter.generated.h"

class UAbilitySystemComponent;
class UMBCharacterMovementComponent;
class UMBComboAttackComponent;
class UMBEquipComponent;

UCLASS(config=Game)
class AMBBaseCharacter : public ACharacter
{

	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AMBBaseCharacter(const FObjectInitializer& ObjectInitializer);

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
	void Attack();
	
	UFUNCTION(BlueprintPure)
	bool CanAttack() const;
	
public:
	
	UMBEquipComponent* GetEquipComponent() const { return  CharacterEquipComponent; };
	UMBComboAttackComponent* GetComboAttackComponent() const { return CharacterComboAttackComponent; };
	FORCEINLINE UMBCharacterMovementComponent* GetBaseCharacterMovementComponent() const { return BaseCharacterMovementComponent;}

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAbilitySystemComponent* AbilitySystemComponent;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBEquipComponent* CharacterEquipComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMBComboAttackComponent* CharacterComboAttackComponent;

	UMBCharacterMovementComponent* BaseCharacterMovementComponent;

};

