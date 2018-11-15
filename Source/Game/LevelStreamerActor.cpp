// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelStreamerActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameCharacter.h"
#include "Engine/World.h"
#include "MyGameInstance.h"
#include "GameGameMode.h"

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
		FLatentActionInfo LatentInfo;
		switch (StreamType)
		{
		case EStreamType::None:
			if (levelToLoad != "")
			{
				if (levelToLoad == "MainMenu")
				{
					auto GameMode = Cast<AGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
					if (GameMode)
					{
						GameMode->UpdateBestRunStats();
					}

					auto GameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
					auto Player = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
					if (GameInstance && Player)
					{
						GameInstance->setLastTotalDeaths(Player->GetDeaths());
						GameInstance->setLastElapsedTime(GetWorld()->GetTimeSeconds());
					}
				}
				UGameplayStatics::OpenLevel(GetWorld(), levelToLoad);
			}

			break;
		case EStreamType::Load:
			if(levelToLoad != "")
				UGameplayStatics::LoadStreamLevel(GetWorld(), levelToLoad, true, false, LatentInfo);
			break;
		case EStreamType::Unload:
			if(levelToUnLoad != "")
				UGameplayStatics::UnloadStreamLevel(GetWorld(), levelToUnLoad, LatentInfo, false);
			break;
		}
		
	}
}
