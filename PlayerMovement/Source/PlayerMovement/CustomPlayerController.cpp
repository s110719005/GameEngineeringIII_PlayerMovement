// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

void ACustomPlayerController::PressJump()
{
	if (JumpDelegate.IsBound())
	{
		JumpDelegate.Broadcast();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "PRESS JUMP");
	}
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//Bind action
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressJump);
}

FJumpSignature* ACustomPlayerController::GetJumpDelegate()
{
	return &JumpDelegate;
}
