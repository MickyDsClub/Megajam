// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameGameMode.generated.h"

class USaveLevels;
class UMainMenuWidget;

UCLASS(minimalapi)
class AGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameGameMode();

	virtual void BeginPlay() override;

	void LoadFile();

	void UpdateCompletedLevelsToFile(FString LevelName);

	void UpdateBestRunStats();

	void SaveFile();

	void setMainMenuWidget(UMainMenuWidget* inMainMenuWidget) { mainMenuWidget = inMainMenuWidget; }

	USaveLevels* GetSaveLevels() { return SaveLevels; }

private:
	USaveLevels* SaveLevels;

	UMainMenuWidget* mainMenuWidget;
};

