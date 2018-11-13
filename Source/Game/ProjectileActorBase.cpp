// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileActorBase.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "GameCharacter.h"
AProjectileActorBase::AProjectileActorBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bSweepCollision = false;
}

void AProjectileActorBase::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AProjectileActorBase::BeginOverlap);
}

void AProjectileActorBase::BeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (Player && OtherActor->IsA(AGameCharacter::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapping Player"));
		Player->RestartLevel();
	}
	Destroy();
}
