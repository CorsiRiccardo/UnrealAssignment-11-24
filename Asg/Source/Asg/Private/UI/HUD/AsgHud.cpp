// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/UI/HUD/AsgHud.h"
#include "UI/Widgets/AsgUserWidget.h"

void AAsgHud::BeginPlay()
{
	Super::BeginPlay();

	InitOverlay();
}

void AAsgHud::InitOverlay()
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class uninitialized"));

	UUserWidget* UserWidget = CreateWidget<UAsgUserWidget>(GetWorld(),OverlayWidgetClass);

	// OverlayWidget = Cast<UAsgUserWidget>(UserWidget);
	UserWidget->AddToViewport();
}
