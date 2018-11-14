// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	bool GetIsStreamingLevel() { return bIsStreamingLevel; }
	void SetIsStreamingLevel(bool value) { bIsStreamingLevel = value; }

private:
	bool bIsStreamingLevel = false;
};
