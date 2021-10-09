// A library file to store Enumeration Types, State Types and any other Static Definitions needed for the game

#pragma once

#include "CoreMinimal.h"

// An Enumerate for the types of Ground Platforms used for the game
UENUM(BlueprintType)
enum class EPointerTypes : uint8
{
	VE_RawPtr		UMETA(DisplayName = "Raw"),
	VE_SharedPtr	UMETA(DisplayName = "Shared Pointer"),
	VE_SharedRef	UMETA(DisplayName = "Shared Reference"),
	VE_UniquePtr	UMETA(DisplayName = "Unique Pointer"),
	VE_WeakPtr		UMETA(DisplayName = "Weak Pointer"),
};