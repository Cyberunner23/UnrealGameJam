// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnowShooterGameMode.generated.h"

UCLASS(minimalapi)
class ASnowShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASnowShooterGameMode();

	/** Find a player start for the player's team */
	AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT(""));
};
