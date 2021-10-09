// Fill out your copyright notice in the Description page of Project Settings.
#include "PointerReferencer.h"
#include "PointersManager.h"

// Sets default values
APointerReferencer::APointerReferencer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APointerReferencer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APointerReferencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointerReferencer::SetReferenceActive(bool bActivate)
{
	if (bActivate && !IsReferenceValid())
	{
		ReferencePtr = PointerManagerRef->GetSharedPointerRef();
	}
	else if (!bActivate && IsReferenceValid())
	{
		PointerManagerRef->OnSharedPointerDereferenced();
		ReferencePtr.Reset();
	}
}