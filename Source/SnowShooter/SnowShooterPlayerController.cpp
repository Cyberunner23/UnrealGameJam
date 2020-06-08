// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterPlayerController.h"
#include "SnowShooterPlayerState.h"


bool ASnowShooterPlayerController::SetTeamFromMenu_Validate(int NewTeamIndex)
{
	// 0 and 1 are valid teams, and -1 is 'unset' team.
	return -1 <= NewTeamIndex && NewTeamIndex <= 1;
}

void ASnowShooterPlayerController::SetTeamFromMenu_Implementation(int NewTeamIndex)
{
	auto _Player = GetPlayerState<ASnowShooterPlayerState>();
	_Player->TeamIndex = NewTeamIndex;

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::Printf(TEXT("new %d real %d"), NewTeamIndex, _Player->TeamIndex));
}