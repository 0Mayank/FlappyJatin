// Fill out your copyright notice in the Description page of Project Settings.


#include "FlippyBirbPawn.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AFlippyBirbPawn::AFlippyBirbPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlippyBirbPawn::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
}


void AFlippyBirbPawn::Fly(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		FVector NewVelocity = FVector(0.0f, 0.0f, FlyVelocity);
		if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(GetRootComponent()))
		{
			PrimitiveComponent->SetPhysicsLinearVelocity(NewVelocity, bAddToCurrent);
		}
	}
}

// Called every frame
void AFlippyBirbPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlippyBirbPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(FlyAction, ETriggerEvent::Started, this, &AFlippyBirbPawn::Fly);
	}
}

