// Fill out your copyright notice in the Description page of Project Settings.


#include "ScrollingComponent.h"
#include  "LevelManager.h"
#include "SpawnerBase.h"

// Sets default values for this component's properties
UScrollingComponent::UScrollingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UScrollingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (const AActor* ParentActor = GetOwner())
	{
		if (const ASpawnerBase* Spawner = Cast<ASpawnerBase>(ParentActor->GetOwner()))
		{
			if (ALevelManager* Ref = Cast<ALevelManager>(Spawner->GetLevelManager()))
			{
				LevelManager = Ref;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Scrolling Component: No Level Manager found"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Scrolling Component: No Spawner found"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Scrolling Component: Parent Actor not found"));
	}
}


// Called every frame
void UScrollingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const AActor* Owner = GetOwner();
	if (Owner)
	{
		if (LevelManager)
		{
			FVector Location = Owner->GetActorLocation();
			Location.X += LevelManager->LevelSpeed * DeltaTime;
			GetOwner()->SetActorLocation(Location, true);
		} else
		{
			UE_LOG(LogTemp, Error, TEXT("Scrolling Component: No Level Manager found"));
		}
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("Scrolling Component: No Owner found"));
	}
}

