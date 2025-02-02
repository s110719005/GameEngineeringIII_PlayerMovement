// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomPlayerControllerInterface.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PLAYERMOVEMENT_API ACustomPlayerController : public APlayerController, public ICustomPlayerControllerInterface
{
	GENERATED_BODY()
public:
	void PressJump();
	void PressForward();
	void PressBackward();
	void ReleaseForward();
	void ReleaseBackward();

protected:
	virtual void SetupInputComponent();
	virtual FJumpSignature* GetJumpDelegate() override;
	virtual FForwardSignature* GetForwardDelegate() override;
	virtual FBackwardSignature* GetBackwardDelegate() override;
	virtual FBackwardSignature* GetBackwardReleaseDelegate() override;
	virtual FBackwardSignature* GetForwardReleaseDelegate() override;
private:
	FJumpSignature JumpDelegate;
	FForwardSignature ForwardDelegate;
	FForwardSignature ForwardReleaseDelegate;
	FBackwardSignature BackwardDelegate;
	FBackwardSignature BackwardReleaseDelegate;

};
