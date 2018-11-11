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
	// Sets default values for this actor's properties
	ACannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Shoot();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectileActorBase> Projectile;

	UPROPERTY(EditAnywhere)
		float fireRate;

	UPROPERTY(EditAnywhere)
		FVector gunOffset;
private:

	bool bCanShoot;

	FTimerHandle  CanShootTimerHandle;

	void ResetCanShoot();
};
