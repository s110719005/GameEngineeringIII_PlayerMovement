// Fill out your copyright notice in the Description page of Project Settings.


#include "IdlePlayerState.h"

void UIdlePlayerState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "START IDLE");

}

void UIdlePlayerState::PressJump()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "SWITCH STATE TO JUMP");
	if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("Jump");
	}
}
