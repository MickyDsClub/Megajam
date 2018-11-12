// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "GameGameMode.h"
#include "SaveLevels.h"

bool UMainMenuWidget::Initialize()
{
	bool Success = Super::Initialize();

	playButton->OnClicked.AddDynamic(this, &UMainMenuWidget::onPlayButtonClicked);
	changeLevelButton->OnClicked.AddDynamic(this, &UMainMenuWidget::onChangeLevelButtonClicked);
	quitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::onQuitButtonClicked);
	backToMainMenuButton->OnClicked.AddDynamic(this, &UMainMenuWidget::onBackToMainMenuButtonClicked);
	level1Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel1ButtonClicked);
	level2Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel2ButtonClicked);
	level3Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel3ButtonClicked);
	level4Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel4ButtonClicked);
	level5Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel5ButtonClicked);
	level6Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel6ButtonClicked);

	// Using SaveLevels to check what levels to be clickable / showable
	auto GameMode = Cast<AGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		SaveLevels = GameMode->GetSaveLevels();
		if (SaveLevels)
		{
			levelsCompletedText->SetText(FText::FromString("Levels completed: " + FString::FormatAsNumber(SaveLevels->LevelsCompleted)));

			switch (SaveLevels->LevelsCompleted)
			{
			case 6:
				level6Button->SetVisibility(ESlateVisibility::Visible);
			case 5:
				level5Button->SetVisibility(ESlateVisibility::Visible);
			case 4:
				level4Button->SetVisibility(ESlateVisibility::Visible);
			case 3:
				level3Button->SetVisibility(ESlateVisibility::Visible);
			case 2:
				level2Button->SetVisibility(ESlateVisibility::Visible);
			case 1:
				level1Button->SetVisibility(ESlateVisibility::Visible);
			}
		}
	}
	return Success;
}

void UMainMenuWidget::onPlayButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_1"), TRAVEL_Absolute);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
}

void UMainMenuWidget::onChangeLevelButtonClicked()
{
	widgetSwitcher->SetActiveWidgetIndex(1);
}

void UMainMenuWidget::onQuitButtonClicked()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->ConsoleCommand("quit");
}

void UMainMenuWidget::onBackToMainMenuButtonClicked()
{
	widgetSwitcher->SetActiveWidgetIndex(0);
}

void UMainMenuWidget::onLevel1ButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_1"), TRAVEL_Absolute);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
}

void UMainMenuWidget::onLevel2ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 2)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_2"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel3ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 3)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_3"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel4ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 4)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_4"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel5ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 5)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_5"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel6ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 6)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_6"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}
