// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/AsgGameMode.h"

void AAsgGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CurrentCooldown += DeltaSeconds;
	if (CurrentCooldown >= TickCooldown)
	{
		CurrentCooldown = 0;
		CurrentHeight += HeightPerTick;
		OnHeightChanged.Broadcast(CurrentHeight);
	}
}
