// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GameCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "TimeDilatedActorBase.h"
#include "Engine/World.h"

AGameCharacter::AGameCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->bUsePawnControlRotation = true;
}

void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	//saves the startlocation of each map, so the player can respawn there.
}

void AGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AGameCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGameCharacter::LookUpAtRate);
}

void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<ATimeDilatedActorBase*> actorsToBeDestroyed;
	for (auto& Actor : TimeDilatedActors)
	{
		if (Actor)
		{
			if (Actor->GetCanBeDestroyed())
			{
				actorsToBeDestroyed.Add(Actor);
			}
			else
			{
				Actor->SetCustomTimeDilation(GetMovementComponent()->Velocity.Size() / GetMovementComponent()->GetMaxSpeed());
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("NULLPTR in TimeDilatedActors TArray"));
		}
	}

	for (auto& Actor : actorsToBeDestroyed)
	{
		if (Actor)
		{
			TimeDilatedActors.Remove(Actor);
			Actor->Destroy();
			Actor = nullptr;
		}
	}
}

void AGameCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGameCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGameCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGameCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AGameCharacter::RestartLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("Running Function: MoveToSpawn"));

	UGameplayStatics::OpenLevel(GetWorld(), FName(*UGameplayStatics::GetCurrentLevelName(GetWorld())));
}
