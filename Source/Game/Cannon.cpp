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

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	bCanShoot = true;
	fireRate = 1.f;
	gunOffset = FVector(100.f, 0.f, 0.f);
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
				World->SpawnActor<AProjectileActorBase>(Projectile, GetActorLocation() + gunOffset, GetActorRotation());
				bCanShoot = false;
			}
			World->GetTimerManager().SetTimer(CanShootTimerHandle, this, &ACannon::ResetCanShoot, fireRate);
		}
	}
}

void ACannon::ResetCanShoot()
{
	bCanShoot = true;
}
