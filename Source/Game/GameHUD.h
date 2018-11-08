// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

UCLASS()
class AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
};

