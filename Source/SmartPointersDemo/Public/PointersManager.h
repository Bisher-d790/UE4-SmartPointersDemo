// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointersManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAction);

UCLASS()
class SMARTPOINTERSDEMO_API APointersManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APointersManager();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Shared Pointer")
		TSubclassOf<class APointerReferencedActor> PointerClass = nullptr;

#pragma region Shared Pointer
private:
	TSharedPtr<class PointerReferencedObject> SharedPointerObjectPtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Shared Pointer")
		TArray<class APointerReferencer*> SharedPointerReferencers;

	UPROPERTY(EditInstanceOnly, Category = "Shared Pointer")
		AActor* SharedPointerObjectSpawnPos;

	UPROPERTY(BlueprintAssignable, Category = "Shared Pointer")
		FOnAction OnSharedPointerActivated;

	UPROPERTY(BlueprintAssignable, Category = "Shared Pointer")
		FOnAction OnSharedPointerDeactivated;

public:
	TSharedPtr<class PointerReferencedObject> GetSharedPointerRef();

	UFUNCTION(BlueprintCallable, Category = "Shared Pointer")
		int GetSharedPointerRefsCount();

	void OnSharedPointerDereferenced();
#pragma endregion

#pragma region Weak Pointer
private:
	TSharedPtr<class PointerReferencedObject> WeakPointerObjectPtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Weak Pointer")
		TArray<class APointerReferencer*> WeakPointerReferencers;

	UPROPERTY(EditInstanceOnly, Category = "Weak Pointer")
		AActor* WeakPointerObjectSpawnPos;

	UPROPERTY(BlueprintAssignable, Category = "Weak Pointer")
		FOnAction OnWeakPointerActivated;

	UPROPERTY(BlueprintAssignable, Category = "Weak Pointer")
		FOnAction OnWeakPointerDeactivated;

public:
	TSharedPtr<class PointerReferencedObject> GetWeakPointerRef();

	UFUNCTION(BlueprintCallable, Category = "Weak Pointer")
		int GetWeakPointerRefsCount();

	void OnWeakPointerDereferenced();
#pragma endregion

#pragma region Shared Reference
#pragma endregion

#pragma region Unique Pointer
#pragma endregion
};