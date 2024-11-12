// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/AsgSpawner.h"


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
	
}

// Called every frame
void AAsgSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

