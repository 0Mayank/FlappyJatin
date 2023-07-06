// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelManager.h"
#include "GameFramework/Actor.h"
#include "SpawnerBase.generated.h"

UCLASS()
class FLIPPYBIRB_API ASpawnerBase : public AActor
{
	GENERATED_BODY()

	FTimerHandle SpawnTimerHandle;
	
public:	
	// Sets default values for this actor's properties
	ASpawnerBase();

	UFUNCTION()
	void SpawnActor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Spawned Actors Management")
	void SpawnedActorHitBounds(AActor* Actor);

	UFUNCTION(BlueprintImplementableEvent)
	void Init();

	UFUNCTION(BlueprintCallable)
	ALevelManager* GetLevelManager() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning Behaviour")
	int NumberOfActors = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning Behaviour")
	FVector DistanceBetweenActors = FVector();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning Behaviour")
	float DelayBetweenSpawns = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning Behaviour")
	bool bRepeat = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawning Behaviour")
	UClass* ActorClassToBeSpawned;

	UPROPERTY(BlueprintReadWrite)
	ALevelManager* LevelManager;

	UPROPERTY(BlueprintReadWrite)
	FVector RespawnLocation = GetActorLocation();

	UPROPERTY(BlueprintReadWrite)
	AActor* LastSpawnedActor;
};
