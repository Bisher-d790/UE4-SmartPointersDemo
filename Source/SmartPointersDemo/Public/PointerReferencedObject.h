// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class SMARTPOINTERSDEMO_API PointerReferencedObject
{
public:
	PointerReferencedObject(class APointerReferencedActor* ActorObjectRef);

	~PointerReferencedObject();

protected:

	class APointerReferencedActor* ActorObject;

public:

	FORCEINLINE class APointerReferencedActor* GetActorObject() { return ActorObject; };

	FORCEINLINE void SetActorObject(class APointerReferencedActor* ActorObjectRef) { ActorObject = ActorObjectRef; };

};
