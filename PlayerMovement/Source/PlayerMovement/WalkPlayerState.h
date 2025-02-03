// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "WalkPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERMOVEMENT_API UWalkPlayerState : public UPlayerBaseState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector movingVector;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FRotator rotation;
protected:
	virtual void OnEnterState(AActor* OwnerRef) override;
	virtual void PressJump() override;
	virtual void ReleaseBackward() override;
	virtual void ReleaseForward() override;
	virtual void TickState() override;
	
};
