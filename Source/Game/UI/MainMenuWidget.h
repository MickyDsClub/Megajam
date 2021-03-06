// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class UButton;
class UWidgetSwitcher;
class UTextBlock;
class USaveLevels;

/**
 * 
 */
UCLASS()
class GAME_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

private:
	UFUNCTION()
	void onPlayButtonClicked();

	UFUNCTION()
	void onChangeLevelButtonClicked();

	UFUNCTION()
	void onQuitButtonClicked();

	UFUNCTION()
	void onBackToMainMenuButtonClicked();

	UFUNCTION()
	void onLevel1ButtonClicked();

	UFUNCTION()
	void onLevel2ButtonClicked();

	UFUNCTION()
	void onLevel3ButtonClicked();

	UFUNCTION()
	void onLevel4ButtonClicked();

	UFUNCTION()
	void onLevel5ButtonClicked();

	UFUNCTION()
	void onLevel6ButtonClicked();

	UFUNCTION()
	void onLevel7ButtonClicked();

	UFUNCTION()
	void onLevel8ButtonClicked();

	UFUNCTION()
	void onLevel9ButtonClicked();

	UFUNCTION()
	void onLevel10ButtonClicked();

	UFUNCTION()
	void onLevel11ButtonClicked();

	void updateLastFullRun();

	void updateBestFullRun();

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* widgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	UButton* playButton;

	UPROPERTY(meta = (BindWidget))
	UButton* changeLevelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* quitButton;

	UPROPERTY(meta = (BindWidget))
	UButton* backToMainMenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* level1Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level2Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level3Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level4Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level5Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level6Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level7Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level8Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level9Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level10Button;

	UPROPERTY(meta = (BindWidget))
	UButton* level11Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* levelsCompletedText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* lastElapsedTimeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* lastTotalDeathsText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* bestElapsedTimeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* bestTotalDeathsText;

	USaveLevels* SaveLevels;
};
