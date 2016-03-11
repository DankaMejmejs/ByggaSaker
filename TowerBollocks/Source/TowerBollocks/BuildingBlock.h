// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BuildingBlock.generated.h"

UCLASS()
class TOWERBOLLOCKS_API ABuildingBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingBlock();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void PickUp();
	
private: 
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* block;

	bool used;
};
