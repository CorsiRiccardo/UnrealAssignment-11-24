// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/AsgSpawner.h"

#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pawns/AsgEnemy.h"
#include "Pawns/AsgPawnBase.h"


// Sets default values
AAsgSpawner::AAsgSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
}

// Called when the game starts or when spawned
void AAsgSpawner::BeginPlay()
{
	Super::BeginPlay();

	check(EnemyClass);
	
}

void AAsgSpawner::SpawnEnemies(int32 Amount) const
{
	for (int32 i = 0; i < Amount; i++)
	{
		FVector Location = GetRandomSpawnLocationInBox();
		FRotator Rotation = GetActorRotation();
		FActorSpawnParameters SpawnInfo;
		
		GetWorld()->SpawnActor<AAsgEnemy>(EnemyClass,Location, Rotation, SpawnInfo);
	}
}

FVector AAsgSpawner::GetRandomSpawnLocationInBox() const
{
	if (!BoxComponent) return GetActorLocation();
	
	// Get the box extent scaled by the component's scale
	const FVector BoxExtent = BoxComponent->GetScaledBoxExtent();

	// Get the center of the box in world space
	const FVector BoxCenter = BoxComponent->GetComponentLocation();

	// Generate a random point within the box's local bounds
	const FVector RandomPointInBox = UKismetMathLibrary::RandomPointInBoundingBox(BoxCenter, BoxExtent);

	return RandomPointInBox;
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

