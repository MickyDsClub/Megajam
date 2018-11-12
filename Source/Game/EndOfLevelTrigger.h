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
		//void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	UPROPERTY(EditAnywhere)
		bool bDrawBox;
private:

	AGameCharacter* Player;

	AGameGameMode* GameMode;

	UPROPERTY(EditAnywhere)
		FString NextLevelName;

};
