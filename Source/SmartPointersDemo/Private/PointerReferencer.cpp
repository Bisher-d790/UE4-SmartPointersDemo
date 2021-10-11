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
		if (PointerManagerType == EPointerTypes::VE_SharedPtr)
		{
			SharedReferencePtr = PointerManagerRef->GetSharedPointerRef();
		}
		else if (PointerManagerType == EPointerTypes::VE_WeakPtr)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedReferencePtr = PointerManagerRef->GetWeakPointerRef();
			else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
				WeakReferencePtr = TWeakPtr<PointerReferencedObject>(PointerManagerRef->GetWeakPointerRef());
		}

		if (!IsReferenceValid())return;

		OnReferenceActivated.Broadcast();
	}
	else if (!bActivate && IsReferenceValid())
	{
		if (PointerManagerType == EPointerTypes::VE_SharedPtr)
		{
			SharedReferencePtr.Reset();
			PointerManagerRef->OnSharedPointerDereferenced();
		}
		else if (PointerManagerType == EPointerTypes::VE_WeakPtr)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedReferencePtr.Reset();
			else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
				WeakReferencePtr.Reset();

			PointerManagerRef->OnWeakPointerDereferenced();
		}

		if (IsReferenceValid())return;

		OnReferenceDeactivated.Broadcast();
	}
}

void APointerReferencer::ToggleReferenceActiveState()
{
	SetReferenceActive(!IsReferenceValid());
}

bool APointerReferencer::IsReferenceValid()
{
	if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
	{
		return SharedReferencePtr.IsValid();
	}
	else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
	{
		return WeakReferencePtr.IsValid();
	}
	return false;
};