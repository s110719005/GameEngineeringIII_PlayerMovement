// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "PlayerCharacter.h"
#include "CustomPlayerController.h"
#include "PlayerBaseState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERMOVEMENT_API UPlayerBaseState : public UStateBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	APlayerCharacter* PlayerRef = nullptr;

	ICustomPlayerControllerInterface* PlayerController = nullptr;
	virtual void OnEnterState(AActor* OwnerRef) override;
	virtual void OnExitState() override;
protected:
	virtual void PressJump();
	virtual void TickState() override;
};
