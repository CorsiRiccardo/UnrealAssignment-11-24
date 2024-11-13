// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AsgGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASG_API UAsgGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:
	
	int Win = 0;
	int Loss = 0;

	void ReloadCurrentLevel() const;
public:
	void GameEnded(bool Result);
	
	FORCEINLINE int GetWin() const {return Win;};
	FORCEINLINE int GetLoss() const {return Loss;};
};
