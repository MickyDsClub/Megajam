// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class GAME_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

private:

	UFUNCTION()
	void onResumeButtonClicked();

	UFUNCTION()
	void onBackToMainMenuButtonClicked();

	UPROPERTY(meta = (BindWidget))
	UButton* resumeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* backToMainMenuButton;
};
