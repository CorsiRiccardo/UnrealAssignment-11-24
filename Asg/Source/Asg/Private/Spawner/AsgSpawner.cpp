// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/AsgSpawner.h"

#include "Pawns/AsgEnemy.h"
#include "Pawns/AsgPawnBase.h"


// Sets default values
AAsgSpawner::AAsgSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsgSpawner::BeginPlay()
{
	Super::BeginPlay();

	check(EnemyClass);
	
}

void AAsgSpawner::SpawnEnemies(int32 Amount)
{
	for (int32 i = 0; i < Amount; i++)
	{
		FVector Location = GetActorLocation();
		FRotator Rotation = GetActorRotation();
		FActorSpawnParameters SpawnInfo;
		
		GetWorld()->SpawnActor<AAsgEnemy>(EnemyClass,Location, Rotation, SpawnInfo);
	}
}

// Called every frame
void AAsgSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LastSpawnTimeElapsed+= DeltaTime;
	if(LastSpawnTimeElapsed >= EnemySpawnTime)
	{
		LastSpawnTimeElapsed = 0;
		SpawnEnemies(1);
	}
}

