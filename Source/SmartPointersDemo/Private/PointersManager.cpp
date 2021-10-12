// Fill out your copyright notice in the Description page of Project Settings.
#include "PointersManager.h"
#include "PointerReferencer.h"
#include "PointerReferencedObject.h"
#include "PointerReferencedActor.h"


// Sets default values
APointersManager::APointersManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

#pragma region Shared Pointer
TSharedPtr<PointerReferencedObject> APointersManager::GetSharedPointerRef()
{
	if (!SharedPointerObjectPtr.IsValid())
	{
		SharedPointerObjectPtr = MakeShareable(new PointerReferencedObject(Cast<APointerReferencedActor>(GetWorld()->SpawnActor(PointerClass))));
		SharedPointerObjectPtr->GetActorObject()->Setup(this, EPointerTypes::VE_SharedPtr);

		if (IsValid(SharedPointerObjectSpawnPos))
			SharedPointerObjectPtr->GetActorObject()->SetActorLocation(SharedPointerObjectSpawnPos->GetActorLocation());

		OnSharedPointerActivated.Broadcast();
	}

	return SharedPointerObjectPtr;
}

void APointersManager::OnSharedPointerDereferenced()
{
	for (auto& ReferencerIndex : SharedPointerReferencers)
	{
		if (ReferencerIndex->IsReferenceValid())
			return;
	}

	SharedPointerObjectPtr.Reset();

	OnSharedPointerDeactivated.Broadcast();
}

int APointersManager::GetSharedPointerRefsCount()
{
	int referenceNum = 0;

	if (SharedPointerObjectPtr.IsValid())
	{
		referenceNum = SharedPointerObjectPtr.GetSharedReferenceCount();
	}
	else
	{
		for (auto& ReferencerIndex : SharedPointerReferencers)
		{
			if (ReferencerIndex->IsReferenceValid())
				referenceNum++;
		}
	}

	return referenceNum;
}
#pragma endregion

#pragma region Weak Pointer
TSharedPtr<PointerReferencedObject> APointersManager::GetWeakPointerRef()
{
	if (!WeakPointerObjectPtr.IsValid())
	{
		WeakPointerObjectPtr = MakeShareable(new PointerReferencedObject(Cast<APointerReferencedActor>(GetWorld()->SpawnActor(PointerClass))));
		WeakPointerObjectPtr->GetActorObject()->Setup(this, EPointerTypes::VE_WeakPtr);

		if (IsValid(WeakPointerObjectSpawnPos))
			WeakPointerObjectPtr->GetActorObject()->SetActorLocation(WeakPointerObjectSpawnPos->GetActorLocation());

		OnWeakPointerActivated.Broadcast();
	}

	return WeakPointerObjectPtr;
}

void APointersManager::OnWeakPointerDereferenced()
{
	for (auto& ReferencerIndex : WeakPointerReferencers)
	{
		if (ReferencerIndex->GetPointerType() == EPointerTypes::VE_SharedPtr && ReferencerIndex->IsReferenceValid())
			return;
	}

	WeakPointerObjectPtr.Reset();

	OnWeakPointerDeactivated.Broadcast();
}

int APointersManager::GetWeakPointerRefsCount()
{
	int referenceNum = 0;

	if (WeakPointerObjectPtr.IsValid())
	{
		referenceNum = WeakPointerObjectPtr.GetSharedReferenceCount();
	}
	else
	{
		for (auto& ReferencerIndex : WeakPointerReferencers)
		{
			if (ReferencerIndex->IsReferenceValid())
				referenceNum++;
		}
	}

	return referenceNum;
}
#pragma endregion

#pragma region Shared Reference
TSharedPtr<PointerReferencedObject> APointersManager::GetSharedReferenceRef()
{
	if (!SharedReferenceObjectPtr.IsValid())
	{
		TSharedRef<PointerReferencedObject>TempRef = TSharedRef<PointerReferencedObject>(new PointerReferencedObject(Cast<APointerReferencedActor>(GetWorld()->SpawnActor(PointerClass))));
		TempRef->GetActorObject()->Setup(this, EPointerTypes::VE_SharedRef);

		if (IsValid(SharedReferenceObjectSpawnPos))
			TempRef->GetActorObject()->SetActorLocation(SharedReferenceObjectSpawnPos->GetActorLocation());

		OnSharedReferenceActivated.Broadcast();

		SharedReferenceObjectPtr = TSharedPtr<PointerReferencedObject>(TempRef);
	}

	return SharedReferenceObjectPtr;
}

void APointersManager::OnSharedReferenceDereferenced()
{
	for (auto& ReferencerIndex : SharedReferenceReferencers)
	{
		if (ReferencerIndex->IsReferenceValid())
			return;
	}

	SharedReferenceObjectPtr.Reset();

	OnSharedReferenceDeactivated.Broadcast();
}

int APointersManager::GetSharedReferenceRefsCount()
{
	int referenceNum = 0;

	if (SharedReferenceObjectPtr.IsValid())
	{
		referenceNum = SharedReferenceObjectPtr.GetSharedReferenceCount();
	}
	else
	{
		for (auto& ReferencerIndex : SharedReferenceReferencers)
		{
			if (ReferencerIndex->IsReferenceValid())
				referenceNum++;
		}
	}

	return referenceNum;
}
#pragma endregion

#pragma region Unique Pointer
#pragma endregion