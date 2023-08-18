#include "MBCharacterController.h"

#include "Powns/BaseCharacter/MBBaseCharacter.h"


void AMBCharacterController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	CachedBaseCharacter = Cast<AMBBaseCharacter>(InPawn);

}

void AMBCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AMBCharacterController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMBCharacterController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMBCharacterController::Turn);
	InputComponent->BindAxis("LookUp", this, &AMBCharacterController::LookUp);

	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMBCharacterController::Jump);
	InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMBCharacterController::Attack);

	
}

void AMBCharacterController::MoveForward(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveForward(Value);

	}
}

void AMBCharacterController::MoveRight(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->MoveRight(Value);

	}
}

void AMBCharacterController::Turn(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Turn(Value);

	}
}

void AMBCharacterController::LookUp(float Value)
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->LookUp(Value);

	}
}

void AMBCharacterController::Jump()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Jump();
	}
}

void AMBCharacterController::Attack()
{
	if (CachedBaseCharacter.IsValid())
	{
		CachedBaseCharacter->Attack();
	}
}
