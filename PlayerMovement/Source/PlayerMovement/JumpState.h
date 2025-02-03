// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "JumpState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERMOVEMENT_API UJumpState : public UPlayerBaseState
{
	GENERATED_BODY()
protected:
	virtual void OnEnterState(AActor* OwnerRef) override;
	virtual void PressJump() override;
	virtual void TickState() override;

};
