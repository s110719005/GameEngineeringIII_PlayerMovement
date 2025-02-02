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
		PlayerController->GetForwardDelegate()->AddUObject(this, &UPlayerBaseState::PressForward);
		PlayerController->GetForwardReleaseDelegate()->AddUObject(this, &UPlayerBaseState::ReleaseForward);
		PlayerController->GetBackwardDelegate()->AddUObject(this, &UPlayerBaseState::PressBackward);
		PlayerController->GetBackwardReleaseDelegate()->AddUObject(this, &UPlayerBaseState::ReleaseBackward);
	}

	if (!animationMesh)
	{
		animationMesh = OwnerRef->FindComponentByClass<USkeletalMeshComponent>();
	}
}

void UPlayerBaseState::OnExitState()
{
	Super::OnExitState();
	//Remove delegate
	PlayerController->GetJumpDelegate()->RemoveAll(this);
	if (PlayerController)
	{
		PlayerController->GetJumpDelegate()->RemoveAll(this);
		PlayerController->GetJumpDelegate()->RemoveAll(this);
		PlayerController->GetForwardDelegate()->RemoveAll(this);
		PlayerController->GetForwardReleaseDelegate()->RemoveAll(this);
		PlayerController->GetBackwardDelegate()->RemoveAll(this);
		PlayerController->GetBackwardReleaseDelegate()->RemoveAll(this);
	}
}

void UPlayerBaseState::PressJump()
{
}

void UPlayerBaseState::PressForward()
{

}

void UPlayerBaseState::PressBackward()
{
}

void UPlayerBaseState::ReleaseBackward()
{
}

void UPlayerBaseState::ReleaseForward()
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
