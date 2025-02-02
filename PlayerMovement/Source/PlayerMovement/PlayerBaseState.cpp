// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBaseState.h"
#include <Kismet/GameplayStatics.h>

void UPlayerBaseState::OnEnterState(AActor* OwnerRef)
{
	Super::OnEnterState(OwnerRef);

	//save player ref for later
	if (!PlayerRef)
	{
		PlayerRef = Cast<APlayerCharacter>(OwnerRef);
	}

	if (!PlayerController)
	{
		PlayerController = Cast<ICustomPlayerControllerInterface>(UGameplayStatics::GetPlayerController(this, 0));
	}

	//bind delegate
	if (PlayerController)
	{
		PlayerController->GetJumpDelegate()->AddUObject(this, &UPlayerBaseState::PressJump);
	}
}

void UPlayerBaseState::OnExitState()
{
	Super::OnExitState();
	//Remove delegate
	PlayerController->GetJumpDelegate()->RemoveAll(this);
}

void UPlayerBaseState::PressJump()
{
}

void UPlayerBaseState::TickState()
{
	//check if moving on ground
	Super::TickState();
	/*if (PlayerRef)
	{
		PlayerRef->StateManager->SwitchStateByKey("Jump");
	}*/
}
