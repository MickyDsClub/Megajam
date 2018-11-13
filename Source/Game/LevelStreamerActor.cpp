// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelStreamerActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameCharacter.h"

ALevelStreamerActor::ALevelStreamerActor()
{
	PrimaryActorTick.bCanEverTick = true;

	OverlapVolume = CreateDefaultSubobject<UBoxComponent>("OverlapVolume");
	RootComponent = OverlapVolume;


}

void ALevelStreamerActor::BeginPlay()
{
	Super::BeginPlay();

	OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamerActor::OverlapBegin);
}

void ALevelStreamerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelStreamerActor::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AGameCharacter::StaticClass()))
	{
		if (levelToLoad != "")
		{
			FLatentActionInfo LatentInfo;
			UGameplayStatics::LoadStreamLevel(this, levelToLoad, true, true, LatentInfo);
		}
		else if (levelToUnLoad != "")
		{
			FLatentActionInfo LatentInfo;
			UGameplayStatics::UnloadStreamLevel(this, levelToUnLoad, LatentInfo, true);
		}
	}
}
