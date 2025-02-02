// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "IdlePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERMOVEMENT_API UIdlePlayerState : public UPlayerBaseState
{
	GENERATED_BODY()
protected:
	virtual void OnEnterState(AActor* OwnerRef) override;
	virtual void PressJump() override;
};
