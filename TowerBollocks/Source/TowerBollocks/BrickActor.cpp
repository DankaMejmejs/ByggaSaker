// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBollocks.h"
#include "BrickActor.h"


// Sets default values
ABrickActor::ABrickActor()
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
	//block->BodyInstance.bLockXTranslation = true;
	//block->BodyInstance.bLockYTranslation = true;
	//block->BodyInstance.bLockZRotation = true;
	//block->BodyInstance.bLockYRotation = true;
	//block->BodyInstance.bLockXRotation = true;
}

// Called when the game starts or when spawned
void ABrickActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrickActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	/*
	if (held) {
		block->BodyInstance.bSimulatePhysics = false;
		block->BodyInstance.SetEnableGravity(false);
		block->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		UE_LOG(LogTemp, Warning, TEXT("Held"));

	}
	else {
		block->BodyInstance.bSimulatePhysics = true;
		block->BodyInstance.SetEnableGravity(true);
		block->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

		UE_LOG(LogTemp, Warning, TEXT("Not held"));
	}
	*/
}

void ABrickActor::StartHover() {
	EventStartHover();
}

void ABrickActor::EndHover() {
	EventEndHover();
}

void ABrickActor::BeginHold(){
	EventBeginHold();
	ServerSetHeld(true);
}

void ABrickActor::EndHold(){
	EventEndHold();
	ServerSetHeld(false);
}


bool ABrickActor::ServerSetHeld_Validate(bool held) {
	return true; 
}
void ABrickActor::ServerSetHeld_Implementation(bool held) {
	this->held = held;
}

