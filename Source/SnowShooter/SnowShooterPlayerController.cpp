// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterPlayerController.h"
#include "SnowShooterPlayerState.h"
#include "Engine/World.h"
#include "GameFramework/Gamemode.h"


bool ASnowShooterPlayerController::SetTeamFromMenu_Validate(int NewTeamIndex)
{
	// 0 and 1 are valid teams, and -1 is 'unset' team.
	return -1 <= NewTeamIndex && NewTeamIndex <= 1;
}

void ASnowShooterPlayerController::SetTeamFromMenu_Implementation(int NewTeamIndex)
{
	auto _Player = GetPlayerState<ASnowShooterPlayerState>();
	_Player->TeamIndex = NewTeamIndex;

	if (NewTeamIndex != -1)
	{
		// Set to a new valid team.
		// RestartPlayer wasn't working ;( so set the transform manually.
		// Won't actually create a new pawn though!
		auto SpawnTransform = GetWorld()->GetAuthGameMode()->FindPlayerStart(this)->GetActorTransform();
		SpawnTransform.SetScale3D({ 1.f, 1.f, 1.f });
		GetPawn()->SetActorTransform(SpawnTransform);
	}
}