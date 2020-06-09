// Copyright Epic Games, Inc. All Rights Reserved.

#include "SnowShooterGameMode.h"
#include "SnowShooterHUD.h"
#include "SnowShooterCharacter.h"
#include "SnowShooterPlayerState.h"
#include "SnowShooterGameState.h"
#include "GameFramework/Controller.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "TimerManager.h"

ASnowShooterGameMode::ASnowShooterGameMode()
	: Super()
	, MatchDuration(180.f) // 3mins
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASnowShooterHUD::StaticClass();

	PlayerStateClass = ASnowShooterPlayerState::StaticClass();
	GameStateClass = ASnowShooterGameState::StaticClass();

	// I'll hard code the player controller just to be consistent with the above.
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassFinder(TEXT("/Game/SnowShooter/Core/BP_SnowShooterPlayerController"));
	PlayerControllerClass = PlayerControllerClassFinder.Class;
}

AActor* ASnowShooterGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	const auto PlayerState = Player->GetPlayerState<ASnowShooterPlayerState>();
	const auto& PlayerStartTag = FString::Printf(TEXT("Team%d"), PlayerState->TeamIndex);
	return Super::FindPlayerStart_Implementation(Player, PlayerStartTag);
}

void ASnowShooterGameMode::StartMatch()
{
	auto A = GetGameState<ASnowShooterGameState>();
	GetWorld()->GetTimerManager().SetTimer(A->MatchTimer, [this] { EndMatch(); }, MatchDuration, false);
}

void ASnowShooterGameMode::EndMatch()
{
	int Team1Count = 0, Team2Count = 0;
	auto _GameState = GetWorld()->GetGameState<ASnowShooterGameState>();
	for (const auto FlagTeam : _GameState->FlagOccupiers)
	{
		switch (FlagTeam)
		{
		case 0:
			Team1Count++;
			break;
		case 1:
			Team2Count++;
			break;
		}
	}
	int Winner;
	if (Team1Count > Team2Count)
		Winner = 0;
	else if (Team2Count > Team1Count)
		Winner = 1;
	else
		// Unlikely, both teams had the same number of flags, but give team 0 the victory.
		// So long as the world has an odd number of flags this probably wouldn't happen!
		Winner = 0;

	// Set winner in game state for clients to see.
	_GameState->WinningTeam = Winner;

	// Load the restart match map after a short delay.
	auto RestartMatch = [this] {
		GetWorld()->ServerTravel(this->RestartMatchMap);
	};

	FTimerHandle NoTimer;
	GetWorld()->GetTimerManager().SetTimer(NoTimer, RestartMatch, 10.f, false);
}

void ASnowShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle NoTimer;
	// Start match after a short delay to let other objects get initialized. Players can still join a team at any time.
	GetWorld()->GetTimerManager().SetTimer(NoTimer, [this] { StartMatch(); }, 0.2f, false);
}
