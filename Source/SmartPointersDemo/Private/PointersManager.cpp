// Fill out your copyright notice in the Description page of Project Settings.
#include "PointersManager.h"
#include "PointerReferencer.h"
#include "PointerReferencedActor.h"


// Sets default values
APointersManager::APointersManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APointersManager::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void APointersManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSharedPtr<APointerReferencedActor> APointersManager::GetSharedPointerRef()
{
	if (!SharedPointerObjectPtr.IsValid())
	{
		SharedPointerObjectPtr = TSharedPtr<APointerReferencedActor>(Cast<APointerReferencedActor>(GetWorld()->SpawnActor(SharedPointerClass)));

		if (IsValid(SharedPointerObjectSpawnPos))
			SharedPointerObjectPtr->SetActorLocation(SharedPointerObjectSpawnPos->GetActorLocation());

		SharedPointerObjectPtr->Setup(this, EPointerTypes::VE_SharedPtr);

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