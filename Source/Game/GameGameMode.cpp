// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GameGameMode.h"
#include "GameHUD.h"
#include "GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/Char.h"
#include "SaveLevels.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/MainMenuWidget.h"

AGameGameMode::AGameGameMode()
	: Super()
{
}

void AGameGameMode::BeginPlay() 
{
	Super::BeginPlay();

	LoadFile();
	if (SaveLevels->LevelsCompleted >= 1) 
	{
		UE_LOG(LogTemp, Warning, TEXT("%i Levels completed!"), SaveLevels->LevelsCompleted);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Level 1 is NOT complete!"));
	}
	SaveFile();
}

void AGameGameMode::LoadFile()
{
	UE_LOG(LogTemp, Warning, TEXT("Trying to load savefile"));
	SaveLevels = Cast<USaveLevels>(UGameplayStatics::CreateSaveGameObject(USaveLevels::StaticClass()));
	SaveLevels = Cast<USaveLevels>(UGameplayStatics::LoadGameFromSlot(SaveLevels->SaveSlotName, SaveLevels->UserIndex));
	if (SaveLevels == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't load save savefile, creating a new savefile"));
		SaveLevels = Cast<USaveLevels>(UGameplayStatics::CreateSaveGameObject(USaveLevels::StaticClass()));
	}
	UE_LOG(LogTemp, Warning, TEXT("Savefile successfully loaded"));
}

void AGameGameMode::UpdateCompletedLevelsToFile(FString LevelName)
{
	LoadFile();

	auto ListOfChars = LevelName.Right(2);
	UE_LOG(LogTemp, Warning, TEXT("Level name: %s"), *ListOfChars);

	if (ListOfChars.StartsWith("_"))
	{
		ListOfChars = ListOfChars.Right(1);
	}
	UE_LOG(LogTemp, Warning, TEXT("Level name AFTER replace: %s"), *ListOfChars);
	int level = FCString::Atoi(*ListOfChars);
	UE_LOG(LogTemp, Warning, TEXT("Level name: %i"), level);
	if (SaveLevels->LevelsCompleted < level) 
	{
		SaveLevels->LevelsCompleted = level;
	}

	SaveFile();
}

void AGameGameMode::SaveFile()
{
	UE_LOG(LogTemp, Warning, TEXT("Trying to save savefile"));
	if (UGameplayStatics::SaveGameToSlot(SaveLevels, SaveLevels->SaveSlotName, SaveLevels->UserIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("Savefile successfully saved"));
	}
}