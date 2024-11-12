﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AsgUserWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class ASG_API UAsgUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HeightAmount;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* MaxHeightAmount;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WinAmountText;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* LossAmountText;

	UFUNCTION()
	void SetWin(int Win) const;
	
	UFUNCTION()
	void SetLoss(int Loss) const;

	UFUNCTION()
	void SetCurrentHeight(float InHeight) const;

	UFUNCTION()
	void SetMaxHeight(float InMaxHeight) const;
};
