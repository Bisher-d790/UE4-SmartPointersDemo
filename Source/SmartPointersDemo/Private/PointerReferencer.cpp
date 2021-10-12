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
			SharedPtrReferencePtr = PointerManagerRef->GetSharedPointerRef();
		}
		else if (PointerManagerType == EPointerTypes::VE_WeakPtr)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedPtrReferencePtr = PointerManagerRef->GetWeakPointerRef();
			else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
				WeakPtrReferencePtr = TWeakPtr<PointerReferencedObject>(PointerManagerRef->GetWeakPointerRef());
		}
		else if (PointerManagerType == EPointerTypes::VE_SharedRef)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedPtrReferencePtr = PointerManagerRef->GetSharedReferenceRef();
			if (PointerReferenceType == EPointerTypes::VE_SharedRef)
			{
				//To show how to declare a SharedRef
				TSharedRef<PointerReferencedObject>TempPtr = PointerManagerRef->GetSharedReferenceRef().ToSharedRef();
				SharedPtrReferencePtr = TSharedPtr<PointerReferencedObject>(TempPtr);
			}
		}

		if (!IsReferenceValid())return;

		OnReferenceActivated.Broadcast();
	}
	else if (!bActivate && IsReferenceValid())
	{
		if (PointerManagerType == EPointerTypes::VE_SharedPtr)
		{
			SharedPtrReferencePtr.Reset();
			PointerManagerRef->OnSharedPointerDereferenced();
		}
		else if (PointerManagerType == EPointerTypes::VE_WeakPtr)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedPtrReferencePtr.Reset();
			else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
				WeakPtrReferencePtr.Reset();

			PointerManagerRef->OnWeakPointerDereferenced();
		}
		else if (PointerManagerType == EPointerTypes::VE_SharedRef)
		{
			if (PointerReferenceType == EPointerTypes::VE_SharedPtr)
				SharedPtrReferencePtr.Reset();
			if (PointerReferenceType == EPointerTypes::VE_SharedRef)
				return;
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
		return SharedPtrReferencePtr.IsValid();
	}
	else if (PointerReferenceType == EPointerTypes::VE_WeakPtr)
	{
		return WeakPtrReferencePtr.IsValid();
	}
	if (PointerReferenceType == EPointerTypes::VE_SharedRef)
	{
		return SharedPtrReferencePtr.IsValid();
	}
	return false;
};