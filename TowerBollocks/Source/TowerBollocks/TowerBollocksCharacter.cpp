// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TowerBollocks.h"
#include "TowerBollocksCharacter.h"
#include "TowerBollocksProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// ATowerBollocksCharacter

ATowerBollocksCharacter::ATowerBollocksCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATowerBollocksCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	//InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATowerBollocksCharacter::TouchStarted);
	if( EnableTouchscreenMovement(InputComponent) == false )
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &ATowerBollocksCharacter::OnClick);
	}
	
	InputComponent->BindAxis("MoveForward", this, &ATowerBollocksCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ATowerBollocksCharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &ATowerBollocksCharacter::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &ATowerBollocksCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &ATowerBollocksCharacter::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &ATowerBollocksCharacter::LookUpAtRate);
	InputComponent->BindAction("ScrollUp", IE_Pressed, this, &ATowerBollocksCharacter::ScrollUp);
	InputComponent->BindAction("ScrollDown", IE_Pressed, this, &ATowerBollocksCharacter::ScrollDown);
}

void ATowerBollocksCharacter::AddControllerYawInput(float value) {
	if (!IsValid(brickActorRef) || !rotateObject) {
		Super::AddControllerYawInput(value);
		return;
	}

	brickActorRef->AddActorLocalRotation(FQuat::MakeFromEuler(FVector(0, 0, -value)));
}
void ATowerBollocksCharacter::AddControllerPitchInput(float value) {
	if (!IsValid(brickActorRef) || !rotateObject) {
		Super::AddControllerPitchInput(value);
		return;
	}

	brickActorRef->AddActorLocalRotation(FQuat::MakeFromEuler(FVector(0, -value, 0)));
}

void ATowerBollocksCharacter::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (IsValid(brickActorRef) && hold)
		brickActorRef->SetActorLocation(FirstPersonCameraComponent->GetComponentLocation() + (FirstPersonCameraComponent->GetForwardVector() * holdDistance));
}

void ATowerBollocksCharacter::OnClick()
{
	//FHitResult hit(ForceInit);
	//FVector CamLoc;
	//FRotator CamRot;

	//holdDistance = 200;

	//Controller->GetActorEyesViewPoint(CamLoc, CamRot);
	//const FVector start = CamLoc;
	//const FVector dir = CamRot.Vector();
	//const FVector end = start + dir * 100;
	//FCollisionQueryParams TraceParams(FName(TEXT("HandTrace")), true, this);
	//TraceParams.bTraceAsyncScene = true;
	//TraceParams.bReturnPhysicalMaterial = true;
	////GetWorld()->LineTraceSingle(hit, start, end, TraceParams, FCollisionObjectQueryParams());
	//GetWorld()->LineTraceSingleByObjectType(hit, start, end, FCollisionObjectQueryParams::AllDynamicObjects);
	//UE_LOG(LogTemp, Warning, TEXT("Fired"));
	//UE_LOG(LogTemp, Warning, TEXT("%i"), hit.GetActor());
	//ABrickActor* brickson = Cast<ABrickActor>(hit.GetActor());
	//if (brickson != NULL)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("A brick is just a brick son"));
	//}
}

void ATowerBollocksCharacter::ScrollUp() {
	holdDistance += 50;
	holdDistance = FMath::Clamp<float>(holdDistance, 200, 400);
}

void ATowerBollocksCharacter::ScrollDown() {
	holdDistance -= 50;
	holdDistance = FMath::Clamp<float>(holdDistance, 200, 400);
}

void ATowerBollocksCharacter::BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if( TouchItem.bIsPressed == true )
	{
		return;
	}
	TouchItem.bIsPressed = true;
	TouchItem.FingerIndex = FingerIndex;
	TouchItem.Location = Location;
	TouchItem.bMoved = false;
}

void ATowerBollocksCharacter::EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if (TouchItem.bIsPressed == false)
	{
		return;
	}
	if( ( FingerIndex == TouchItem.FingerIndex ) && (TouchItem.bMoved == false) )
	{
		OnClick();
	}
	TouchItem.bIsPressed = false;
}

void ATowerBollocksCharacter::TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	if ((TouchItem.bIsPressed == true) && ( TouchItem.FingerIndex==FingerIndex))
	{
		if (TouchItem.bIsPressed)
		{
			if (GetWorld() != nullptr)
			{
				UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
				if (ViewportClient != nullptr)
				{
					FVector MoveDelta = Location - TouchItem.Location;
					FVector2D ScreenSize;
					ViewportClient->GetViewportSize(ScreenSize);
					FVector2D ScaledDelta = FVector2D( MoveDelta.X, MoveDelta.Y) / ScreenSize;									
					if (ScaledDelta.X != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.X * BaseTurnRate;
						AddControllerYawInput(Value);
					}
					if (ScaledDelta.Y != 0.0f)
					{
						TouchItem.bMoved = true;
						float Value = ScaledDelta.Y* BaseTurnRate;
						AddControllerPitchInput(Value);
					}
					TouchItem.Location = Location;
				}
				TouchItem.Location = Location;
			}
		}
	}
}

void ATowerBollocksCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATowerBollocksCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATowerBollocksCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATowerBollocksCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

bool ATowerBollocksCharacter::EnableTouchscreenMovement(class UInputComponent* InputComponent)
{
	bool bResult = false;
	if(FPlatformMisc::GetUseVirtualJoysticks() || GetDefault<UInputSettings>()->bUseMouseForTouch )
	{
		bResult = true;
		InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ATowerBollocksCharacter::BeginTouch);
		InputComponent->BindTouch(EInputEvent::IE_Released, this, &ATowerBollocksCharacter::EndTouch);
		InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ATowerBollocksCharacter::TouchUpdate);
	}
	return bResult;
}
