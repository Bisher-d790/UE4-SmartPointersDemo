// Fill out your copyright notice in the Description page of Project Settings.
#include "PointerReferencedActor.h"


// Sets default values
APointerReferencedActor::APointerReferencedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void APointerReferencedActor::Setup(class APointersManager* PointersManager, EPointerTypes PointerType)
{
	PointersManagerRef = PointersManager;
	PointerReferenceType = PointerType;
}