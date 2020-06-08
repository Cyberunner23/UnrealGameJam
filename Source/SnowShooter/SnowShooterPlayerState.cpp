// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterPlayerState.h"
#include "Net/UnrealNetwork.h"

ASnowShooterPlayerState::ASnowShooterPlayerState()
	: TeamIndex(-1)
{}

void ASnowShooterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASnowShooterPlayerState, TeamIndex);
}
