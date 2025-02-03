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

void ACustomPlayerController::PressForward()
{
	if (ForwardDelegate.IsBound())
	{
		ForwardDelegate.Broadcast();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "PRESS FORWARD");
	}
}

void ACustomPlayerController::PressBackward()
{
	if (BackwardDelegate.IsBound())
	{
		BackwardDelegate.Broadcast();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "PRESS BACKWARD");
	}
}

void ACustomPlayerController::ReleaseForward()
{
	if (ForwardReleaseDelegate.IsBound())
	{
		ForwardReleaseDelegate.Broadcast();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "RELEASE FORWARD");
	}
}

void ACustomPlayerController::ReleaseBackward()
{
	if (BackwardReleaseDelegate.IsBound())
	{
		BackwardReleaseDelegate.Broadcast();
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "RELEASE BACKWARD");
	}
}

void ACustomPlayerController::QuitGame()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//Bind action
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressJump);
	InputComponent->BindAction("Forward", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressForward);
	InputComponent->BindAction("Forward", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleaseForward);
	InputComponent->BindAction("Backward", EInputEvent::IE_Pressed, this, &ACustomPlayerController::PressBackward);
	InputComponent->BindAction("Backward", EInputEvent::IE_Released, this, &ACustomPlayerController::ReleaseBackward);
	InputComponent->BindAction("Quit", EInputEvent::IE_Released, this, &ACustomPlayerController::QuitGame);
}

FJumpSignature* ACustomPlayerController::GetJumpDelegate()
{
	return &JumpDelegate;
}

FForwardSignature* ACustomPlayerController::GetForwardDelegate()
{
	return &ForwardDelegate;
}

FBackwardSignature* ACustomPlayerController::GetBackwardDelegate()
{
	return &BackwardDelegate;
}

FBackwardSignature* ACustomPlayerController::GetBackwardReleaseDelegate()
{
	return &BackwardReleaseDelegate;
}

FBackwardSignature* ACustomPlayerController::GetForwardReleaseDelegate()
{
	return &ForwardReleaseDelegate;
}
