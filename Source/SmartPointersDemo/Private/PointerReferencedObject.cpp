// Fill out your copyright notice in the Description page of Project Settings.


#include "PointerReferencedObject.h"
#include "PointerReferencedActor.h"

PointerReferencedObject::PointerReferencedObject(APointerReferencedActor* ActorObjectRef)
{
	ActorObject = ActorObjectRef;
}

PointerReferencedObject::~PointerReferencedObject()
{
	if (IsValid(ActorObject))
		ActorObject->Destroy();
}