// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Pawns/AsgEnemy.h"

void AAsgEnemy::BeginPlay()
{
	Super::BeginPlay();

	checkf(EnemyData,TEXT("Enemy data not set!"));
}
