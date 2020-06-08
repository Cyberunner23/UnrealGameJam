// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SnowShooterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SNOWSHOOTER_API ASnowShooterPlayerState : public APlayerState
{
	GENERATED_BODY()

	ASnowShooterPlayerState();

public:

	/** Team the player is on. */
	UPROPERTY(Replicated, BlueprintReadWrite, Category = Gameplay)
	int32 TeamIndex;

public:
	// AActor interface
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	// End of AActor interface

};
