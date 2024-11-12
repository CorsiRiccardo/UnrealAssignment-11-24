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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AAsgPawnBase>> EntitiesToSpawn;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
