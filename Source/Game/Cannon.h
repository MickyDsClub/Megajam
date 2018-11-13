// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeDilatedActorBase.h"
#include "Cannon.generated.h"

class AProjectileActorBase;

UCLASS()
class GAME_API ACannon : public ATimeDilatedActorBase
{
	GENERATED_BODY()
	
public:	
	ACannon();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	void Shoot();

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATimeDilatedActorBase> Projectile;

	UPROPERTY(EditAnywhere)
	float FireRate;

	UPROPERTY(EditAnywhere)
	float GunOffset;

	UPROPERTY(EditDefaultsOnly)
	class USoundBase* ShootSound;

	float TimerTime;
};
