// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Pawns/AsgHero.h"

#include "AsgGameMode.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"


void AAsgHero::OnHealthChangedResponse(int32 NewHealth)
{
	Super::OnHealthChangedResponse(NewHealth);

	if (NewHealth <= 0)
	{
		if (const auto AsgGameMode = Cast<AAsgGameMode>(UGameplayStatics::GetGameMode(this)))
		{
			AsgGameMode->NotifyHeroDeath();
		}
	}
}

