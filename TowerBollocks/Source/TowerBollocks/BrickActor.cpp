// Fill out your copyright notice in the Description page of Project Settings.

#include "TowerBollocks.h"
#include "BrickActor.h"


// Sets default values
ABrickActor::ABrickActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

}

void ABrickActor::StartHover() {
	EventStartHover();
}

void ABrickActor::EndHover() {
	EventEndHover();
}
