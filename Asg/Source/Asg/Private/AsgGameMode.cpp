// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/AsgGameMode.h"

void AAsgGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(GameEnded) return;
	
	CurrentCooldown += DeltaSeconds;
	if (CurrentCooldown >= TickCooldown)
	{
		CurrentCooldown = 0;
		CurrentHeight += HeightPerTick;
		OnHeightChanged.Broadcast(CurrentHeight);
	}

	if(CurrentHeight >= MaxHeight)
	{
		EndGame(true);
	}
}

void AAsgGameMode::EndGame(bool HasWon)
{
	GameEnded = true;

	if (APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld())))
	{
		MyPlayer->SetPause(true);
	}
}
