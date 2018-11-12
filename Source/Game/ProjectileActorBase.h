// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeDilatedActorBase.h"
#include "ProjectileActorBase.generated.h"

class UProjectileMovementComponent;

UCLASS()
class GAME_API AProjectileActorBase : public ATimeDilatedActorBase
{
	GENERATED_BODY()

public:
	AProjectileActorBase();

	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(class AActor* OverlappedActor, class AActor* OtherActor);

private:
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;
};
