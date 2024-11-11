// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Components/Projectiles/ProjectileBullet.h"
#include "GameFramework/Character.h"
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

void AProjectileBullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                              FVector NormalImpulse, const FHitResult& Hit)
{
	if (const auto OwnerCharacter = Cast<AAsgPawnBase>(GetOwner()))
	{
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

	Super::OnHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}
