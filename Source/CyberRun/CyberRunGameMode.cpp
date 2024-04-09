// Copyright Epic Games, Inc. All Rights Reserved.

#include "CyberRunGameMode.h"
#include "CyberRunCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACyberRunGameMode::ACyberRunGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
