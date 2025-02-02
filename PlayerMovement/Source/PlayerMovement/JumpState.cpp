// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpState.h"

void UJumpState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "START JUMP");
}

void UJumpState::PressJump()
{
	//PlayerRef->Jump();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "JUMP JUMP");
}

void UJumpState::TickState()
{
	Super::TickState();
	////check is moving on ground
	//if (PlayerRef)
	//{
	//	PlayerRef->StateManager->SwitchStateByKey("Jump");

	//}
}
