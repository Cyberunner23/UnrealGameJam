// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowShooterGameState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "TimerManager.h"

ASnowShooterGameState::ASnowShooterGameState()
	: FlagOccupiers{ -1, -1, -1 } // 3 flags to capture, initially unset team index -1
{
	PrimaryActorTick.bCanEverTick = true;
}

float ASnowShooterGameState::GetMatchTimeRemaining()
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(MatchTimer);
}

void ASnowShooterGameState::Tick(float DeltaTime)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		MatchTimeRemaining = GetMatchTimeRemaining();
		// Lets keep this for now in case we don't get a chance to make a proper HUD in time. 
		// Make sure to package in debug mode!
		GEngine->AddOnScreenDebugMessage(3485634, 2.f, FColor::Yellow, *FString::Printf(TEXT("Match time left: %.2fs"), MatchTimeRemaining));
	}
}

void ASnowShooterGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASnowShooterGameState, FlagOccupiers);
	DOREPLIFETIME(ASnowShooterGameState, MatchTimeRemaining);
}