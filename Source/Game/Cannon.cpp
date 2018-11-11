// Fill out your copyright notice in the Description page of Project Settings.

#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

#include "ProjectileActorBase.h"

// Sets default values
ACannon::ACannon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TimerTime = 0;
	FireRate = 0.2f;
	GunOffset = 50.f;
}

// Called when the game starts or when spawned
void ACannon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Does timer like this as FTimerHandle doesnt react to CustomTimeDilation
	TimerTime += DeltaTime;
	if (TimerTime >= FireRate) 
	{
		Shoot();
		TimerTime = 0;
	}
}

void ACannon::Shoot()
{
	UWorld* World = GetWorld();
	if (World)
	{
		if (Projectile)
		{
			World->SpawnActor<AProjectileActorBase>(Projectile, GetActorLocation()+GetActorForwardVector().GetSafeNormal()*GunOffset, GetActorRotation());
		}
	}
}