// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointerReferencer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAction);

UCLASS()
class SMARTPOINTERSDEMO_API APointerReferencer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APointerReferencer();

private:
	TSharedPtr<class APointerReferencedActor> ReferencePtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Reference")
		class APointersManager* PointerManagerRef = nullptr;

	UPROPERTY(BlueprintAssignable, Category = "Reference")
		FOnAction OnReferenceActivated;

	UPROPERTY(BlueprintAssignable, Category = "Reference")
		FOnAction OnReferenceDeactivated;

public:
	UFUNCTION(BlueprintCallable, Category = "Reference")
		FORCEINLINE bool IsReferenceValid() { return ReferencePtr.IsValid(); };

	UFUNCTION(BlueprintCallable, Category = "Reference")
		void SetReferenceActive(bool bActivate);

	UFUNCTION(BlueprintCallable, Category = "Reference")
		void ToggleReferenceActiveState();
};