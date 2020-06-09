// Copyright Epic Games, Inc. All Rights Reserved.

#include "SnowShooterGameMode.h"
#include "SnowShooterHUD.h"
#include "SnowShooterCharacter.h"
#include "SnowShooterPlayerState.h"
#include "SnowShooterGameState.h"
#include "GameFramework/Controller.h"
#include "UObject/ConstructorHelpers.h"

ASnowShooterGameMode::ASnowShooterGameMode()
	: Super()
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
