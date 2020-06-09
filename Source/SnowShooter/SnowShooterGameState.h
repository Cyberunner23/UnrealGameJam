// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SnowShooterGameState.generated.h"

/**
 * 
 */
UCLASS()
class SNOWSHOOTER_API ASnowShooterGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ASnowShooterGameState();

	/** Array of flags with their team's index. -1 indicates the flag is unoccupied. */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = Gameplay)
	TArray<int> FlagOccupiers;

	/** Timer for the match to end. */
	FTimerHandle MatchTimer;

	/** This will be replicated to all clients. */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = Gameplay)
	float MatchTimeRemaining;

	// Called every frame.
	void Tick(float DeltaTime);

private:
	/** [server] Used to set time remaining for clients. */
	float GetMatchTimeRemaining();

public:
	// AActor interface
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	// End of AActor interface

};
