// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/MovingObstacle.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AMovingObstacle::AMovingObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));

}

void AMovingObstacle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AddMovementInput(MovementDirection,1);
}
