// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileActorBase.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectileActorBase::AProjectileActorBase()
{
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;

}
