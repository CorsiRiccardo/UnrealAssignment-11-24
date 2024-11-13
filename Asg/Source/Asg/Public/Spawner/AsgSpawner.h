// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsgSpawner.generated.h"

class UBoxComponent;
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
	TObjectPtr<UBoxComponent> BoxComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> PawnClass;

	void SpawnPawns(int32 Amount) const;
public:

	UPROPERTY(EditAnywhere)
	float SpawnTime = 5;

private:

	float LastSpawnTimeElapsed = 0;
	
	FVector GetRandomSpawnLocationInBox() const;

	
};
