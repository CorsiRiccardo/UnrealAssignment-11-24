// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/MovingObstacle.h"

#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/AsgPawnBase.h"


void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnHit);
}

// Sets default values
AMovingObstacle::AMovingObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);

	BoxComponent->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));
}

void AMovingObstacle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AddMovementInput(MovementDirection, 1);
}

void AMovingObstacle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                            UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetClass() == AAsgPawnBase::StaticClass())
	{
		UGameplayStatics::ApplyDamage(
			OtherActor,
			10,
			GetController(),
			this,
			UDamageType::StaticClass()
		);
	}
	Destroy();
}
