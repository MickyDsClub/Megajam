// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeDilatedActorBase.generated.h"

class AGameCharacter;

UCLASS()
class GAME_API ATimeDilatedActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimeDilatedActorBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	AGameCharacter* Player;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

};
