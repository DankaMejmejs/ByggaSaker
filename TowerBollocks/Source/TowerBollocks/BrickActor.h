// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"
#include "BrickActor.generated.h"

class ATowerBollocksCharacter;

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
		void BeginHold(ATowerBollocksCharacter* val);

	UFUNCTION(BlueprintCallable, Category = Interaction)
		void EndHold();

		

	UFUNCTION(BlueprintCallable, Category = Interaction)
		bool GetUsed();
	void SetUsed(bool val);

	UPROPERTY(BlueprintReadOnly, Replicated)
		ATowerBollocksCharacter* ownerActor;
	
private: 
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* block;

	UPROPERTY(Replicated)
		bool isHeld = false;

	UPROPERTY(Replicated)
		FTransform transform;

	bool used;

	

	
};
