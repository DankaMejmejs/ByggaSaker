// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BrickActor.generated.h"

UCLASS()
class TOWERBOLLOCKS_API ABrickActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrickActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = Interaction)
		void StartHover();
	
	UFUNCTION(BlueprintCallable, Category = Interaction)
		void EndHover();

	UFUNCTION(BlueprintImplementableEvent, Category = Interaction)
		void EventStartHover();

	UFUNCTION(BlueprintImplementableEvent, Category = Interaction)
		void EventEndHover();

	UFUNCTION(BlueprintCallable, Category = Interaction)
		void BeginHold();

	UFUNCTION(BlueprintCallable, Category = Interaction)
		void EndHold();

private: 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* block;

	bool used;
};
