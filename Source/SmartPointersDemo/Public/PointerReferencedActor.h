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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	EPointerTypes PointerReferenceType;

	TSharedPtr<class APointersManager> PointersManagerRef;

public:
	void Setup(class APointersManager* Manager, EPointerTypes PointerType);

	FORCEINLINE void SetPointerType(EPointerTypes PointerType) { PointerReferenceType = PointerType; };

	UFUNCTION(BlueprintCallable, Category = "Reference")
		FORCEINLINE class APointersManager* GetPointerManagerRef() { return PointersManagerRef.Get(); };
};
