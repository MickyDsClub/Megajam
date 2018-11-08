// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeDilatedActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
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
}

void ATimeDilatedActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

