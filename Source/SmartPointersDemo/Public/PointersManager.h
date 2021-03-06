// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointerReferencedObject.h"
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
private:
	TSharedPtr<class PointerReferencedObject> SharedReferenceObjectPtr;

	UPROPERTY(EditInstanceOnly, Category = "Shared Reference")
		TArray<class APointerReferencer*> SharedReferenceReferencers;

	UPROPERTY(EditInstanceOnly, Category = "Shared Reference")
		AActor* SharedReferenceObjectSpawnPos;

	UPROPERTY(BlueprintAssignable, Category = "Shared Reference")
		FOnAction OnSharedReferenceActivated;

	UPROPERTY(BlueprintAssignable, Category = "Shared Reference")
		FOnAction OnSharedReferenceDeactivated;

public:
	TSharedPtr<class PointerReferencedObject> GetSharedReferenceRef();

	UFUNCTION(BlueprintCallable, Category = "Shared Reference")
		int GetSharedReferenceRefsCount();

	void OnSharedReferenceDereferenced();
#pragma endregion

#pragma region Unique Pointer
private:
	TUniquePtr<class PointerReferencedObject> UniquePointerObjectPtr = nullptr;

	UPROPERTY(EditInstanceOnly, Category = "Unique Pointer")
		TArray<class APointerReferencer*> UniquePointerReferencers;

	UPROPERTY(EditInstanceOnly, Category = "Unique Pointer")
		AActor* UniquePointerObjectSpawnPos;

	UPROPERTY(BlueprintAssignable, Category = "Unique Pointer")
		FOnAction OnUniquePointerActivated;

	UPROPERTY(BlueprintAssignable, Category = "Unique Pointer")
		FOnAction OnUniquePointerDeactivated;

public:
	TUniquePtr<class PointerReferencedObject> GetUniquePointerRef();

	UFUNCTION(BlueprintCallable, Category = "Unique Pointer")
		int GetUniquePointerRefsCount();

	UFUNCTION(BlueprintCallable, Category = "Unique Pointer")
		void OnUniquePointerDereferenced();

	UFUNCTION(BlueprintCallable, Category = "Unique Pointer")
		void OnUniquePointerReferenced();
#pragma endregion
};