// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "EndOfLevelTrigger.generated.h"

class AGameCharacter;
class AGameGameMode;
UCLASS()
class GAME_API AEndOfLevelTrigger : public ATriggerVolume
{
	GENERATED_BODY()

public:

	AEndOfLevelTrigger();

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UPROPERTY(EditAnywhere)
	bool bDrawBox;
private:
	AGameCharacter* Player;

	AGameGameMode* GameMode;

	UPROPERTY(EditAnywhere)
	FString NextLevelName;

	UPROPERTY(EditAnywhere)
	bool bIsLava;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector PlayerSpawnLocation = FVector(0);

};
