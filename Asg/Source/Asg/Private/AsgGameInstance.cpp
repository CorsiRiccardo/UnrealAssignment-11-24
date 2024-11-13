// Fill out your copyright notice in the Description page of Project Settings.


#include "AsgGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UAsgGameInstance::ReloadCurrentLevel() const
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void UAsgGameInstance::GameEnded(const bool Result)
{
	if (Result)
	{
		Win++;
	}else
	{
		Loss++;
	}
	ReloadCurrentLevel();
}
