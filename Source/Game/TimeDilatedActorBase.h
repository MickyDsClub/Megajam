// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeDilatedActorBase.generated.h"

class AGameCharacter;

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	MovesWithPlayer,
	MovesOppositeOfPlayer,
	Default
};

UCLASS()
class GAME_API ATimeDilatedActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimeDilatedActorBase();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetCustomTimeDilation(float NormalizedSpeed);

protected:
	AGameCharacter* Player;

	UPROPERTY(EditAnywhere)
	bool bIsPlatformer;

	UPROPERTY(EditAnywhere)
	float ReturnDelay = 0.2f;

	UPROPERTY(EditAnywhere)
	float Velocity = 500.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation = FVector(0);

	UPROPERTY(EditAnywhere)
	EMovementType MovementType = EMovementType::Default;
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	FVector GlobalStartLocation = FVector(0);

	FVector GlobalTargetLocation = FVector(0);

	FTimerHandle TH_SwapDelay;


	bool bTimerSet = false;
	bool bMovesSameAsPlayer = false;
	bool bMovesOppositeOfPlayer = false;

	void Move(float DeltaTime);

	void SwapDirection();
};
