// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBollocks.h"
#include "BrickDispenserActor.h"


// Sets default values
ABrickDispenserActor::ABrickDispenserActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxBrick = 10;
	currentBrick = 0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	triggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	triggerBox->AttachParent = RootComponent;
	triggerBox->SetCollisionProfileName(TEXT("Trigger"));
}

// Called when the game starts or when spawned
void ABrickDispenserActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABrickDispenserActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (currentBrick < MaxBrick)
	{
		wait += DeltaTime;
		if (wait >= 1.0f)
		{
			SpawnBrick();
			wait = 0.0f;
		}
	
	}
}

void ABrickDispenserActor::TookABrick()
{
	currentBrick--;
	UE_LOG(LogTemp, Warning, TEXT("Took a brick"));
}

void ABrickDispenserActor::SpawnBrick()
{
	currentBrick++;

	ABrickActor* brick = GetWorld()->SpawnActor<ABrickActor>(ABrickActor::StaticClass());
	FTransform pos = FTransform();
	pos.SetLocation(GetTransform().GetLocation());
	pos.SetScale3D(brick->GetTransform().GetScale3D());
	brick->SetActorTransform(pos);

}

