// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TowerBollocks.h"
#include "TowerBollocksGameMode.h"
#include "TowerBollocksHUD.h"
#include "TowerBollocksCharacter.h"

ATowerBollocksGameMode::ATowerBollocksGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATowerBollocksHUD::StaticClass();
}
