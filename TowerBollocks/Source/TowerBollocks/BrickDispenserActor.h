// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BrickActor.h"
#include "GameFramework/Actor.h"
#include "BrickDispenserActor.generated.h"

UCLASS()
class TOWERBOLLOCKS_API ABrickDispenserActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrickDispenserActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void TookABrick();
	void SpawnBrick();
	
private:
	//ABrickActor& brick;
	

	int32 MaxBrick;
	int32 currentBrick;

	float wait = 0.0f;
};
