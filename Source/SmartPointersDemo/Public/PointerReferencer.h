// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointerReferencer.generated.h"

UCLASS()
class SMARTPOINTERSDEMO_API APointerReferencer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APointerReferencer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TSharedPtr<class APointerReferencedActor> ReferencePtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Reference")
		class APointersManager* PointerManagerRef = nullptr;

public:
	UFUNCTION(BlueprintCallable, Category = "Reference")
		FORCEINLINE bool IsReferenceValid() { return ReferencePtr.IsValid(); };

	void SetReferenceActive(bool bActivate);
};
