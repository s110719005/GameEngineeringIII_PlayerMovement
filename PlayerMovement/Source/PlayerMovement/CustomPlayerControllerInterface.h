// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CustomPlayerControllerInterface.generated.h"

// This class does not need to be modified.
DECLARE_MULTICAST_DELEGATE(FJumpSignature);
DECLARE_MULTICAST_DELEGATE(FForwardSignature);
DECLARE_MULTICAST_DELEGATE(FBackwardSignature);
UINTERFACE(MinimalAPI)
class UCustomPlayerControllerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PLAYERMOVEMENT_API ICustomPlayerControllerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FJumpSignature* GetJumpDelegate() = 0;
	virtual FForwardSignature* GetForwardDelegate() = 0;
	virtual FBackwardSignature* GetBackwardDelegate() = 0;
	virtual FBackwardSignature* GetBackwardReleaseDelegate() = 0;
	virtual FBackwardSignature* GetForwardReleaseDelegate() = 0;
};
