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


}

void AProjectileActorBase::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AProjectileActorBase::BeginOverlap);
}

void AProjectileActorBase::BeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapping Player"));
		Player->MoveToSpawn();
		//Destroy(); //Bullets will never be deleted, as we must remove them from ther TArray in player so as the game doesnt crash... NEEDS FIXING -HUGE MEMORY LEAK
	}
}
