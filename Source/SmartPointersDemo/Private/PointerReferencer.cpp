// Fill out your copyright notice in the Description page of Project Settings.
#include "PointerReferencer.h"
#include "PointersManager.h"

// Sets default values
APointerReferencer::APointerReferencer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APointerReferencer::SetReferenceActive(bool bActivate)
{
	if (bActivate && !IsReferenceValid())
	{
		ReferencePtr = PointerManagerRef->GetSharedPointerRef();

		OnReferenceActivated.Broadcast();
	}
	else if (!bActivate && IsReferenceValid())
	{
		ReferencePtr.Reset();

		PointerManagerRef->OnSharedPointerDereferenced();

		OnReferenceDeactivated.Broadcast();
	}
}

void APointerReferencer::ToggleReferenceActiveState()
{
	SetReferenceActive(!IsReferenceValid());
}