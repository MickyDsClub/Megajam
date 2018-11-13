// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

class UInputComponent;
class ATimeDilatedActorBase;

UCLASS(config=Game)
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameCharacter();

	virtual void BeginPlay();
	
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	virtual void Tick(float DeltaTime) override;

	void MoveForward(float Val);

	void MoveRight(float Val);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void RestartLevel();

	void CreatePauseWidget();

	float GetNormalizedSpeed() { return NormalizedSpeed; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* Camera;

private:
	float NormalizedSpeed = 0.0f;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UPauseWidget> pauseWidget;
};

