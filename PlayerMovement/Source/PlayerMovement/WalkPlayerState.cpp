// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkPlayerState.h"

void UWalkPlayerState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "START WALK");
	if (animationMesh)
	{
		animationMesh->PlayAnimation(animation, true);
	}
	if (audioComponent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "PLAY JUMP SOUND");
		audioComponent->SetSound(soundWave);
		audioComponent->Play();
	}
}

void UWalkPlayerState::PressJump()
{
	if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("Jump");
	}
}

void UWalkPlayerState::ReleaseBackward()
{
	if (PlayerRef)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "BACK TO IDLE");
		PlayerRef->StateManager->SwitchStateByKey("Idle");
	}
}

void UWalkPlayerState::ReleaseForward()
{
	if (PlayerRef)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "BACK TO IDLE");
		PlayerRef->StateManager->SwitchStateByKey("Idle");
	}
}

void UWalkPlayerState::TickState()
{
	Super::TickState();
	if (PlayerRef)
	{
		PlayerRef->SetActorLocation(PlayerRef->GetActorLocation() + movingVector * 3);
	}
}
