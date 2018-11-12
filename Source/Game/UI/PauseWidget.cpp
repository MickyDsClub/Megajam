// Fill out your copyright notice in the Description page of Project Settings.

#include "PauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UPauseWidget::Initialize()
{
	bool Success = Super::Initialize();

	resumeButton->OnClicked.AddDynamic(this, &UPauseWidget::onResumeButtonClicked);
	backToMainMenuButton->OnClicked.AddDynamic(this, &UPauseWidget::onBackToMainMenuButtonClicked);

	return Success;
}

void UPauseWidget::onResumeButtonClicked()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetInputMode(FInputModeGameOnly());
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
	RemoveFromParent();
}

void UPauseWidget::onBackToMainMenuButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "/Game/Maps/MainMenu", TRAVEL_Absolute);
}