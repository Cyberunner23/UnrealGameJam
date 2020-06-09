// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterGameState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "TimerManager.h"

ASnowShooterGameState::ASnowShooterGameState()
	: FlagOccupiers{ -1, -1, -1 } // 3 flags to capture, initially unset team index -1
{}

float ASnowShooterGameState::GetMatchTimeRemaining()
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(MatchTimer);
}

void ASnowShooterGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASnowShooterGameState, FlagOccupiers);
}