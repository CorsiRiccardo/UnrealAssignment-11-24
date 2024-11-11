// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Pawns/AsgEnemy.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pawns/AsgHero.h"

void AAsgEnemy::BeginPlay()
{
	Super::BeginPlay();

	checkf(EnemyData,TEXT("Enemy data not set!"));
	
	Hero = CastChecked<AAsgHero>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
}

void AAsgEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	LookAtPlayer();
	
}

void AAsgEnemy::LookAtPlayer()
{
	if(Hero.IsValid())
	{
		const FVector Forward = Hero->GetActorLocation() - GetActorLocation();
		const FRotator Rot = UKismetMathLibrary::MakeRotFromXZ(Forward, FVector::UpVector);
		SetActorRotation(Rot, ETeleportType::None);
	}
}
