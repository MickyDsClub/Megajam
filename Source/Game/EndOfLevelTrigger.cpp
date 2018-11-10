// Fill out your copyright notice in the Description page of Project Settings.

#include "EndOfLevelTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#include "GameCharacter.h"

AEndOfLevelTrigger::AEndOfLevelTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AEndOfLevelTrigger::OnOverlapBegin);
	bDrawBox = false;
}
void AEndOfLevelTrigger::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (bDrawBox)
	{
		DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 100, FColor::Cyan, true, -1, 0, 5);
	}

}
void AEndOfLevelTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && (OtherActor == Player))
	{
		// print to screen using above defined method when actor enters trigger volume
		UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
		UE_LOG(LogTemp, Warning, TEXT("Other Actor = %s"), *OtherActor->GetName());

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
