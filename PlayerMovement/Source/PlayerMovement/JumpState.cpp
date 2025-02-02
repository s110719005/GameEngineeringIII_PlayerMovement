// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpState.h"
#include "GameFramework/CharacterMovementComponent.h"

void UJumpState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);
	if (animationMesh)
	{
		animationMesh->PlayAnimation(animation, false);
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "START JUMP");
	}
	if (PlayerRef)
	{
		PlayerRef->Jump();
	}
	
	//move up
}

void UJumpState::PressJump()
{
	//PlayerRef->Jump();
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "JUMP JUMP");
}

void UJumpState::TickState()
{
	Super::TickState();
	////check is moving back to ground
	if (PlayerRef)
	{
		if (PlayerRef->GetCharacterMovement()->IsMovingOnGround())
		{
			PlayerRef->StateManager->SwitchStateByKey("Idle");
		}
	}
}
