// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBollocks.h"
#include "BrickActor.h"


// Sets default values
ABrickActor::ABrickActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Required to replicate variables
	bReplicates = true;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> BlockMesh(TEXT("/Engine/BasicShapes/Cube"));
	block->SetStaticMesh(BlockMesh.Object);
	
	block->BodyInstance.bSimulatePhysics = true;
	FTransform trans = FTransform();
	trans.SetScale3D(FVector(1.0f, 0.5f, 0.5f));
	block->SetRelativeTransform(trans);

	used = false;
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

	// If not server
	if (Role < ROLE_Authority)
		SetActorTransform(transform);
	else
		transform = GetTransform();

	if (isHeld) {
		if (Role == ROLE_Authority)
			block->BodyInstance.bSimulatePhysics = false;
		block->BodyInstance.SetEnableGravity(false);
		block->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	}
	else {
		if (Role == ROLE_Authority)
			block->BodyInstance.bSimulatePhysics = true;
		block->BodyInstance.SetEnableGravity(true);
		block->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	
}

void ABrickActor::StartHover() {
	EventStartHover();
}

void ABrickActor::EndHover() {
	EventEndHover();
}

// Most likely called via RPC on server
void ABrickActor::BeginHold(ATowerBollocksCharacter* val){
	ownerActor = val;
	isHeld = true;
	EventBeginHold();
}

// Most likely called via RPC on server
void ABrickActor::EndHold() {
	isHeld = false;
	EventEndHold();
}


// Some shit that is needed for replicated variables
void ABrickActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {
	DOREPLIFETIME(ABrickActor, isHeld);
	DOREPLIFETIME(ABrickActor, transform);
}

bool ABrickActor::GetUsed()
{
	return used;
}

void ABrickActor::SetUsed(bool val)
{
	used = val;
}