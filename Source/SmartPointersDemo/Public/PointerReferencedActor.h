// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Definitions.h"
#include "PointerReferencedActor.generated.h"

UCLASS()
class SMARTPOINTERSDEMO_API APointerReferencedActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APointerReferencedActor();

protected:
	class APointersManager* PointersManagerRef;

	EPointerTypes PointerReferenceType;

public:
	void Setup(class APointersManager* PointersManager, EPointerTypes PointerType);

	UFUNCTION(BlueprintCallable, Category = "Reference")
		FORCEINLINE EPointerTypes GetPointerType() { return PointerReferenceType; };

	UFUNCTION(BlueprintCallable, Category = "Reference")
		FORCEINLINE class APointersManager* GetPointerManagerRef() { return PointersManagerRef; };
};
