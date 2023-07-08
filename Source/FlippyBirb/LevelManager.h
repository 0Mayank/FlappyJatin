// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelManager.generated.h"

UCLASS()
class FLIPPYBIRB_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelSpeed = -500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector BoundsLocation;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GameOver();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartGame();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
