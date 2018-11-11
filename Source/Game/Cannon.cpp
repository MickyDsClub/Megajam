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


	bCanShoot = true;
	FireRate = 1.f;
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
	Shoot();
}

void ACannon::Shoot()
{
	if (bCanShoot)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			if (Projectile)
			{
				World->SpawnActor<AProjectileActorBase>(Projectile, GetActorLocation()+GetActorForwardVector().GetSafeNormal()*GunOffset, GetActorRotation());
				bCanShoot = false;
			}
			World->GetTimerManager().SetTimer(CanShootTimerHandle, this, &ACannon::ResetCanShoot, FireRate);
		}
	}
}

void ACannon::ResetCanShoot()
{
	bCanShoot = true;
}
