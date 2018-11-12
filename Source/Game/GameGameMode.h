// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameGameMode.generated.h"

class USaveLevels;

UCLASS(minimalapi)
class AGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameGameMode();

	virtual void BeginPlay() override;

	void LoadFile();

	void UpdateCompletedLevelsToFile(FString LevelName);

	void SaveFile();

private:
	USaveLevels* SaveLevels;
};

