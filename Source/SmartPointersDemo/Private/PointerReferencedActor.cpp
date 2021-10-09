// Fill out your copyright notice in the Description page of Project Settings.
#include "PointerReferencedActor.h"
#include "PointersManager.h"


// Sets default values
APointerReferencedActor::APointerReferencedActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APointerReferencedActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APointerReferencedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointerReferencedActor::Setup(APointersManager* Manager, EPointerTypes PointerType)
{
	PointersManagerRef = TSharedPtr<APointersManager>(Manager);

	SetPointerType(PointerType);
}