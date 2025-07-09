// Copyright Epic Games, Inc. All Rights Reserved.

#include "StationGameMode.h"
#include "StationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStationGameMode::AStationGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
