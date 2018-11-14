// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelStreamerActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameCharacter.h"

ALevelStreamerActor::ALevelStreamerActor()
{
	PrimaryActorTick.bCanEverTick = false;

	OverlapVolume = CreateDefaultSubobject<UBoxComponent>("OverlapVolume");
	RootComponent = OverlapVolume;
}

void ALevelStreamerActor::BeginPlay()
{
	Super::BeginPlay();

	OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamerActor::OverlapBegin);
}

void ALevelStreamerActor::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AGameCharacter::StaticClass()))
	{
		if (levelToLoad != "")
		{
			FLatentActionInfo LatentInfo;
			switch (StreamType)
			{
			case EStreamType::None:
				UGameplayStatics::OpenLevel(GetWorld(), levelToLoad);
				break;
			case EStreamType::Load:
				UGameplayStatics::LoadStreamLevel(GetWorld(), levelToLoad, true, false, LatentInfo);
				break;
			case EStreamType::Unload:
				UGameplayStatics::UnloadStreamLevel(GetWorld(), levelToUnLoad, LatentInfo, false);
				break;
			}
		}
	}
}
