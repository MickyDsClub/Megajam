// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeDilatedActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Timermanager.h"

#include "GameCharacter.h"

ATimeDilatedActorBase::ATimeDilatedActorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void ATimeDilatedActorBase::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Player)
	{
		Player->AddTimeDilatedActor(this);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Didn't find player!"));
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void ATimeDilatedActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsPlatformer)
	{
		Move(DeltaTime);
	}
}

// NormalizedSpeed = Player.Velocity / Player.MaxVelocity
void ATimeDilatedActorBase::SetCustomTimeDilation(float NormalizedSpeed)
{
	switch (MovementType)
	{
		case EMovementType::MovesWithPlayer:
			CustomTimeDilation = NormalizedSpeed;
			break;
		case EMovementType::MovesOppositeOfPlayer:
			CustomTimeDilation = 1 - NormalizedSpeed;
			break;
		case EMovementType::Default:
			CustomTimeDilation = 1;
			break;
	}
}

void ATimeDilatedActorBase::Move(float DeltaTime)
{
	FVector Location = GetActorLocation();
	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

	auto DistanceLeftToTravel = FVector::DotProduct((GlobalTargetLocation - Location), Direction);
	if (DistanceLeftToTravel < 0.3f)
	{
		if (!bTimerSet)
		{
			GetWorld()->GetTimerManager().SetTimer(TH_SwapDelay, this, &ATimeDilatedActorBase::SwapDirection, ReturnDelay);
			bTimerSet = true;
		}
	}
	else
	{
		Location += Velocity * DeltaTime * Direction;
		SetActorLocation(Location);
	}
}

void ATimeDilatedActorBase::SwapDirection()
{
	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

	FVector Swap = GlobalStartLocation;
	GlobalStartLocation = GlobalTargetLocation;
	GlobalTargetLocation = Swap;

	bTimerSet = false;
}
