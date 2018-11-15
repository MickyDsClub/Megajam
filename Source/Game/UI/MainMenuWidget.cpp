// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "GameGameMode.h"
#include "SaveLevels.h"
#include "MyGameInstance.h"

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
	level7Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel7ButtonClicked);
	level8Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel8ButtonClicked);
	level9Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel9ButtonClicked);
	level10Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel10ButtonClicked);
	level11Button->OnClicked.AddDynamic(this, &UMainMenuWidget::onLevel11ButtonClicked);

	// Using SaveLevels to check what levels to be clickable / showable
	auto GameMode = Cast<AGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		SaveLevels = GameMode->GetSaveLevels();
		if (SaveLevels)
		{
			levelsCompletedText->SetText(FText::FromString("Levels unlocked: " + FString::FormatAsNumber(SaveLevels->LevelsCompleted)));

			switch (SaveLevels->LevelsCompleted)
			{
			case 11:
				level11Button->SetVisibility(ESlateVisibility::Visible);
			case 10:
				level10Button->SetVisibility(ESlateVisibility::Visible);
			case 9:
				level9Button->SetVisibility(ESlateVisibility::Visible);
			case 8:
				level8Button->SetVisibility(ESlateVisibility::Visible);
			case 7:
				level7Button->SetVisibility(ESlateVisibility::Visible);
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

	updateLastFullRun();
	updateBestFullRun();

	return Success;
}

void UMainMenuWidget::onPlayButtonClicked()
{
	auto GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance)
	{
		GameInstance->SetIsStreamingLevel(true);
		UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/Streaming/s_Main"), TRAVEL_Absolute);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong gameinstance in use!"))
	}
}

void UMainMenuWidget::onChangeLevelButtonClicked()
{
	auto MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	MyGameInstance->SetIsStreamingLevel(false);
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

void UMainMenuWidget::onLevel7ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 7)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_7"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel8ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 8)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_8"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel9ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 9)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_9"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel10ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 10)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_10"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::onLevel11ButtonClicked()
{
	if (SaveLevels)
	{
		if (SaveLevels->LevelsCompleted >= 11)
		{
			UGameplayStatics::OpenLevel(GetWorld(), TEXT("/Game/Maps/level_11"), TRAVEL_Absolute);
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
		}
	}
}

void UMainMenuWidget::updateLastFullRun()
{
	auto GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance)
	{
		auto time = GameInstance->getLastElapsedTime();
		if (time > 0.0f)
		{
			FString minutes = "";
			int mins = FMath::FloorToInt(time / 60);
			if (mins == 1)
			{
				minutes = FString::FromInt(mins) + " minute, ";
			}
			else if (mins > 1)
			{
				minutes = FString::FromInt(mins) + " minutes, ";
			}

			FString seconds = "";
			int secs = time % 60;
			if (secs == 1)
			{
				seconds = FString::FromInt(secs) + " second";
			}
			else if (secs > 1)
			{
				seconds = FString::FromInt(secs) + " seconds";
			}
			lastElapsedTimeText->SetText(FText::FromString(minutes + seconds));

		}
		else
		{
			lastElapsedTimeText->SetText(FText::FromString("-"));
		}

		int deaths = GameInstance->getLastTotalDeaths();
		if (deaths >= 0)
		{
			lastTotalDeathsText->SetText(FText::AsNumber(deaths));
		}
		else
		{
			lastTotalDeathsText->SetText(FText::FromString("-"));
		}
	}
	else
	{
		lastElapsedTimeText->SetText(FText::FromString("-"));
		lastTotalDeathsText->SetText(FText::FromString("-"));
	}
}

void UMainMenuWidget::updateBestFullRun()
{
	if (SaveLevels)
	{
		auto time = SaveLevels->elapsedTime;
		if (time > 0.0f)
		{
			FString minutes = "";
			int mins = FMath::FloorToInt(time / 60);
			if (mins == 1)
			{
				minutes = FString::FromInt(mins) + " minute, ";
			}
			else if (mins > 1)
			{
				minutes = FString::FromInt(mins) + " minutes, ";
			}

			FString seconds = "";
			int secs = time % 60;
			if (secs == 1)
			{
				seconds = FString::FromInt(secs) + " second";
			}
			else if (secs > 1)
			{
				seconds = FString::FromInt(secs) + " seconds";
			}
			bestElapsedTimeText->SetText(FText::FromString(minutes + seconds));

		}
		else
		{
			bestElapsedTimeText->SetText(FText::FromString("-"));
		}

		int deaths = SaveLevels->totalDeaths;
		if (deaths >= 0)
		{
			bestTotalDeathsText->SetText(FText::AsNumber(deaths));
		}
		else
		{
			bestTotalDeathsText->SetText(FText::FromString("-"));
		}
	}
	else
	{
		bestElapsedTimeText->SetText(FText::FromString("-"));
		bestTotalDeathsText->SetText(FText::FromString("-"));
	}
}
