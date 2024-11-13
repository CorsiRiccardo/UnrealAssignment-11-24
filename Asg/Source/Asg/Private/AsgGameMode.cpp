// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/AsgGameMode.h"

#include "AsgGameInstance.h"
#include "Kismet/GameplayStatics.h"

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

void AAsgGameMode::NotifyHeroDeath()
{
	if(GameEnded) return;
	EndGame(false);
}

void AAsgGameMode::EndGame(const bool HasWon)
{
	GameEnded = true;

	OnGameEnded.Broadcast(HasWon);
	if(const auto AsgGameInstance = Cast<UAsgGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		AsgGameInstance->GameEnded(HasWon);
	}
	if (APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld())))
	{
		MyPlayer->SetPause(true);
	}
}
