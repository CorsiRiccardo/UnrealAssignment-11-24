// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/UI/HUD/AsgHud.h"

#include "AsgGameInstance.h"
#include "AsgGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widgets/AsgUserWidget.h"

void AAsgHud::BeginPlay()
{
	Super::BeginPlay();
	GameMode = CastChecked<AAsgGameMode>(UGameplayStatics::GetGameMode(this));
	GameInstance = CastChecked<UAsgGameInstance>(UGameplayStatics::GetGameInstance(this));
	InitOverlay();
}

void AAsgHud::InitOverlay()
{
	checkf(OverlayWidgetClass, TEXT("Overlay widget class uninitialized"));

	OverlayWidget = CreateWidget<UAsgUserWidget>(GetWorld(),OverlayWidgetClass);
	OverlayWidget->SetGameInstance(GameInstance.Get());
	OverlayWidget->SetGameMode(GameMode.Get());
	
	OverlayWidget->AddToViewport();
}
