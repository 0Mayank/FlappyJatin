// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerBase.h"

// Sets default values
ASpawnerBase::ASpawnerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnerBase::SpawnActor()
{
	FVector Location = GetActorLocation();
	FActorSpawnParameters Parameters = FActorSpawnParameters();
	Parameters.Owner = this;
	if (ActorClassToBeSpawned)
	{
		for (int i = 0; i < NumberOfActors; i++) {
			LastSpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &Location, nullptr, Parameters);
			//UE_LOG(LogTemp, Warning, TEXT("Parent %s"), LastSpawnedActor->GetOwner())
			Location += DistanceBetweenActors;
		}
	}
}

ALevelManager* ASpawnerBase::GetLevelManager() const
{
	return LevelManager;
}

// Called when the game starts or when spawned
void ASpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (DelayBetweenSpawns > 0.0f) {
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnerBase::SpawnActor, DelayBetweenSpawns, bRepeat);
	} else
	{
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnerBase::SpawnActor, 0.1, bRepeat);
	}

	Init();
	
	if (bRepeat == false)
	{
		const float DistanceFromBounds = LevelManager->BoundsLocation.X - GetActorLocation().X;
		const float LastSpawnedLocation = GetActorLocation().X + DistanceBetweenActors.X * (NumberOfActors - 1);

		const int Sign = LevelManager->LevelSpeed > 0 ? 1 : (LevelManager->LevelSpeed < 0 ? -1: 0);
		RespawnLocation.X = LastSpawnedLocation - DistanceFromBounds * Sign;
		RespawnLocation += DistanceBetweenActors;
	}
}