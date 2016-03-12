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
			UE_LOG(LogTemp, Warning, TEXT("Hello"));
			UE_LOG(LogTemp, Warning, TEXT("%i"), currentBrick);
			wait = 0.0f;
		}
		//currentBrick++;
		
		
	}
}

void ABrickDispenserActor::TookABrick()
{
	currentBrick--;
}

void ABrickDispenserActor::SpawnBrick()
{
	currentBrick++;
	//const ConstructorHelpers::FClassFinder<ABrickActor> brick(TEXT("/Classes_Game/TowerBollocks/BrickActor"));
	/*if (brick.Class != nullptr)
	{

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SHIT FUCKER"));
	}
	FActorSpawnParameters spawn = FActorSpawnParameters();*/
	
	ABrickActor* brick = GetWorld()->SpawnActor<ABrickActor>(ABrickActor::StaticClass());
	FTransform pos = FTransform();
	pos.SetLocation(GetTransform().GetLocation());
	pos.SetScale3D(brick->GetTransform().GetScale3D());
	brick->SetActorTransform(pos);
	//brick->SetActorTransform(GetTransform());
	//Cast <ABrickActor, AActor>(brick)->SetActorTransform(GetTransform());
	//GetWorld()->SpawnActor(ABrickActor::StaticClass(), GetTransform(),FActorSpawnParameters());
	//ABrickActor().SetActorTransform(GetTransform());
	

}

