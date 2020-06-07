// Copyright Epic Games, Inc. All Rights Reserved.

#include "SnowShooterGameMode.h"
#include "SnowShooterHUD.h"
#include "SnowShooterCharacter.h"
#include "SnowShooterPlayerState.h"
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
}
