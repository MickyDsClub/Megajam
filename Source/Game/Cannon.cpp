// Fill out your copyright notice in the Description page of Project Settings.

#include "Cannon.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

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
	if (Projectile)
	{
		GetWorld()->SpawnActor<ATimeDilatedActorBase>(Projectile, GetActorLocation()+GetActorForwardVector().GetSafeNormal()*GunOffset, GetActorRotation());
		if(ShootSound)
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), ShootSound, GetActorLocation(), 1, FMath::RandRange(0.9f,1.1f));
	}
}