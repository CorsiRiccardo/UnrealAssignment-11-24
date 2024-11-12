// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/AsgUserWidget.h"

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
		WinAmountText->SetText(FText::FromString(LossText));
	}
}

void UAsgUserWidget::SetCurrentHeight(const float InHeight) const
{
	if(WinAmountText)
	{
		const FString InHeightText = FString::Printf(TEXT("%f"), InHeight);
		WinAmountText->SetText(FText::FromString(InHeightText));
	}
}

void UAsgUserWidget::SetMaxHeight(float InMaxHeight) const
{
	if(WinAmountText)
	{
		const FString InMaxHeightText = FString::Printf(TEXT("%f"), InMaxHeight);
		WinAmountText->SetText(FText::FromString(InMaxHeightText));
	}
}
