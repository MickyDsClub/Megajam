// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelStreamerActor.generated.h"

class UBoxComponent;
class UWorld;

UCLASS()
class GAME_API ALevelStreamerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelStreamerActor();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
private:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* OverlapVolume;

	UPROPERTY(EditAnywhere)
	FName levelToLoad = "";

	UPROPERTY(EditAnywhere)
	FName levelToUnLoad = "";

};
