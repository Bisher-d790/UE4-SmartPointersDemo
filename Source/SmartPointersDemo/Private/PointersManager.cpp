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