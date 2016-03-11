// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBollocks.h"
#include "BuildingBlock.h"


// Sets default values
ABuildingBlock::ABuildingBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMesh(TEXT("/Engine/BasicShapes/Cube"));
	block->SetStaticMesh(BlockMesh.Object);
	FTransform trans = FTransform();
	trans.SetScale3D(FVector(1.0f, 0.5f, 0.5f));
	block->SetRelativeTransform(trans);
	block->BodyInstance.bSimulatePhysics = true;
	block->BodyInstance.bLockXTranslation = true;
	block->BodyInstance.bLockYTranslation = true;
	block->BodyInstance.bLockZRotation = true;
	block->BodyInstance.bLockYRotation = true;
	block->BodyInstance.bLockXRotation = true;
}

// Called when the game starts or when spawned
void ABuildingBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingBlock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (used)
	{
		//Följ efter spelaren som har plockat upp stenen
	}

}

void ABuildingBlock::PickUp()
{
	block->BodyInstance.bLockXTranslation = false;
	block->BodyInstance.bLockYTranslation = false;

	used = true;
}

