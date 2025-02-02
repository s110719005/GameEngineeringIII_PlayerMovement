// Fill out your copyright notice in the Description page of Project Settings.


#include "IdlePlayerState.h"

void UIdlePlayerState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "START IDLE");
	if (animationMesh)
	{
		animationMesh->PlayAnimation(animation, true);
	}

}

void UIdlePlayerState::PressJump()
{
	Super::PressJump();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "SWITCH STATE TO JUMP");
	if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("Jump");
	}
}

void UIdlePlayerState::PressForward()
{
	Super::PressForward();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "SWITCH STATE TO Walkcforward");
	if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("WalkForward");
	}
}

void UIdlePlayerState::PressBackward()
{
	Super::PressBackward();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "SWITCH STATE TO Walk backward");
	if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("WalkBackward");
	}
}
