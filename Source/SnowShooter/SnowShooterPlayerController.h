// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SnowShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SNOWSHOOTER_API ASnowShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

		/** Sets the team index from the menu. */
		UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
		void SetTeamFromMenu(int NewTeamIndex);
	
};
