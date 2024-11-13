// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsgSpawner.generated.h"

class AAsgPawnBase;

UCLASS()
class ASG_API AAsgSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAsgSpawner();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AAsgPawnBase> EnemyClass;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AAsgPawnBase>> ObstaclesToSpawn;

	void SpawnEnemies(int32 Amount);
public:

	UPROPERTY(EditAnywhere)
	float EnemySpawnTime = 5;

	UPROPERTY(EditAnywhere)
	float MaxSpawnedEnemies = 10;

private:

	float LastSpawnTimeElapsed = 0;
	
};
