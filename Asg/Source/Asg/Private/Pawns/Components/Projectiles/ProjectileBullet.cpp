// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Components/Projectiles/ProjectileBullet.h"
#include "Kismet/GameplayStatics.h"
#include "Pawns/AsgPawnBase.h"


// Sets default values
AProjectileBullet::AProjectileBullet()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AProjectileBullet::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectileBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectileBullet::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const auto OwnerCharacter = Cast<AAsgPawnBase>(GetOwner()))
	{
		//Make sure that AI doesnt kill itself
		if(OwnerCharacter->GetClass() == OtherActor->GetClass()) return;
		if (const auto OwnerController = OwnerCharacter->GetController(); IsValid(OwnerController))
		{
			UGameplayStatics::ApplyDamage(
				OtherActor,
				Damage,
				OwnerController,
				this,
				UDamageType::StaticClass()
			);
		}
	}

	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
