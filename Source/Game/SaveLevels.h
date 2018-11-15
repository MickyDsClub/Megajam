// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveLevels.generated.h"

UCLASS()
class GAME_API USaveLevels : public USaveGame
{
	GENERATED_BODY()

public:
	USaveLevels();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int LevelsCompleted;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int elapsedTime = -1;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int totalDeaths = -1;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

};
