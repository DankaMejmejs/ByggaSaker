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

	UFUNCTION(BlueprintImplementableEvent, Category = Interaction)
		void EventBeginHold();

	UFUNCTION(BlueprintImplementableEvent, Category = Interaction)
		void EventEndHold();

	//UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation, Category = Interaction)
	UFUNCTION(BlueprintCallable, Category = Interaction)
		void BeginHold();

	UFUNCTION(BlueprintCallable, Category = Interaction)
		void EndHold();

	UFUNCTION(Server, Unreliable, WithValidation)
		void ServerSetHeld(bool held);

private: 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* block;

	UPROPERTY(EditAnywhere)
		bool held = false;
	

	bool used;
};
