// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/AsgUserWidget.h"

#include "AsgGameInstance.h"
#include "AsgGameMode.h"
#include "Components/TextBlock.h"

void UAsgUserWidget::SetWin(const int Win) const
{
	if(WinAmountText)
	{
		const FString WinText = FString::Printf(TEXT("%d"), Win);
		WinAmountText->SetText(FText::FromString(WinText));
	}
}

void UAsgUserWidget::SetLoss(const int Loss) const
{
	if(WinAmountText)
	{
		const FString LossText = FString::Printf(TEXT("%d"), Loss);
		LossAmountText->SetText(FText::FromString(LossText));
	}
}

void UAsgUserWidget::SetCurrentHeight(const float InHeight)
{
	if(WinAmountText)
	{
		const FString InHeightText = FString::Printf(TEXT("%f"), InHeight);
		HeightAmount->SetText(FText::FromString(InHeightText));
	}
}

void UAsgUserWidget::SetMaxHeight(float InMaxHeight) const
{
	if(WinAmountText)
	{
		const FString InMaxHeightText = FString::Printf(TEXT("%f"), InMaxHeight);
		MaxHeightAmount->SetText(FText::FromString(InMaxHeightText));
	}
}

void UAsgUserWidget::SetGameInstance(UAsgGameInstance* InGameInstance)
{
	GameInstance = InGameInstance;
	if(GameInstance.IsValid())
	{
		const int Win = GameInstance->GetWin();
		const int Loss = GameInstance->GetLoss();

		SetWin(Win);
		SetLoss(Loss);
	}
}

void UAsgUserWidget::SetGameMode(AAsgGameMode* InGameMode)
{
	if(GameMode.IsValid())	GameMode.Get()->OnHeightChanged.RemoveDynamic(this,&UAsgUserWidget::SetCurrentHeight);
	
	GameMode = InGameMode;
	if(GameMode.IsValid())
	{
		GameMode.Get()->OnHeightChanged.AddDynamic(this,&UAsgUserWidget::SetCurrentHeight);
	}
}
