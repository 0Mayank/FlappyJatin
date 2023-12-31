// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "FlippyBirbPawn.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class FLIPPYBIRB_API AFlippyBirbPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFlippyBirbPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* FlyAction;

	UPROPERTY(EditAnywhere, Category="Fly Behaviour")
	float FlyVelocity = 100.0f;

	UPROPERTY(EditAnywhere, Category="Fly Behaviour")
	bool bAddToCurrent = true;

	void Fly(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
