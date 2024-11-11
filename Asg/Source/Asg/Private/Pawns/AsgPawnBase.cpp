// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Pawns/AsgPawnBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AAsgPawnBase::AAsgPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	Mesh->SetupAttachment(RootComponent);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(Mesh);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraBoom);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));
}

// Called when the game starts or when spawned
void AAsgPawnBase::BeginPlay()
{
	Super::BeginPlay();

	checkf(Data, TEXT("No data assigned!"));
}

// Called every frame
void AAsgPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
