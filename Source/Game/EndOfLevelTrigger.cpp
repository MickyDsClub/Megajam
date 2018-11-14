// Fill out your copyright notice in the Description page of Project Settings.

#include "EndOfLevelTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#include "GameGameMode.h"
#include "GameCharacter.h"
#include "MyGameInstance.h"

AEndOfLevelTrigger::AEndOfLevelTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AEndOfLevelTrigger::OnOverlapBegin);
	bDrawBox = false;
}

void AEndOfLevelTrigger::BeginPlay()
{
	Super::BeginPlay();
	// Not in use atm
	Player = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));


	if (bDrawBox)
	{
		DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);
	}

}

void AEndOfLevelTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AGameCharacter::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
		UE_LOG(LogTemp, Warning, TEXT("Other Actor = %s"), *OtherActor->GetName());
		
		if (!NextLevelName.IsEmpty())
		{
			GameMode = Cast<AGameGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
			if (GameMode)
			{
				GameMode->UpdateCompletedLevelsToFile(NextLevelName);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("EndOfLevelTrigger: Wrong gamemode in use"))
			}
		}
		// print to screen using above defined method when actor enters trigger volume
		auto Player = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		auto MyGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
		if (MyGameInstance->GetIsStreamingLevel())
		{
			auto SpawnLocation = GetTransform().TransformPosition(PlayerSpawnLocation);
			
			Player->SetSpawnLocation(SpawnLocation);
			if (bIsLava)
			{
				Player->SetActorLocation(SpawnLocation);
			}
		}
		else
		{
			if (!NextLevelName.IsEmpty())
			{
				UGameplayStatics::OpenLevel(GetWorld(), FName(*NextLevelName));
				
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Can't find level with name: %s"), *NextLevelName);
			}
		}
	}
}
