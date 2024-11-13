// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Components/CombatComponent.h"

#include "Pawns/Components/WeaponData.h"
#include "Pawns/Components/Projectiles/Projectile.h"
#include "Pawns/Components/Projectiles/ProjectileBullet.h"


// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = Cast<AAsgPawnBase>(GetOwner());
	ensure(OwnerPawn);
}


void UCombatComponent::Shoot()
{
	if (!CanFire()) return;

	bCanFire = false;

	if (const auto World = GetWorld(); IsValid(World) && IsValid(OwnerPawn))
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = GetOwner();
		SpawnParameters.Instigator = OwnerPawn;

		World->SpawnActor<AProjectile>(
			WeaponData->ProjectileBulletClass,
			OwnerPawn->GetSkeletalMeshComponent()->GetComponentLocation() +
			OwnerPawn->GetSkeletalMeshComponent()->GetForwardVector() * WeaponData->DistanceFromPawn,
			OwnerPawn->GetSkeletalMeshComponent()->GetComponentRotation(),
			SpawnParameters);
	}

	StartFireTimer();
}

bool UCombatComponent::CanFire() const
{
	return bCanFire;
}

void UCombatComponent::StartFireTimer()
{
	OwnerPawn->GetWorldTimerManager().SetTimer(
		FireTimerHandle,
		this,
		&UCombatComponent::FireTimerFinished,
		WeaponData->CooldownTime);
}

void UCombatComponent::FireTimerFinished()
{
	bCanFire = true;
}
