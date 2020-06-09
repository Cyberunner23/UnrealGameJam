// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterGameState.h"
#include "Net/UnrealNetwork.h"

ASnowShooterGameState::ASnowShooterGameState()
	: FlagOccupiers{ -1, -1, -1 }
{}


void ASnowShooterGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASnowShooterGameState, FlagOccupiers);
}