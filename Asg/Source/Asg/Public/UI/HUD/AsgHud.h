// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AsgHud.generated.h"

class UAsgGameInstance;
class AAsgGameMode;
class UAsgUserWidget;
class UAsgWidgetController;
/**
 * 
 */
UCLASS()
class ASG_API AAsgHud : public AHUD
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;
	void InitOverlay();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAsgUserWidget> OverlayWidgetClass;
	
private:

	UPROPERTY()
	TObjectPtr<UAsgUserWidget> OverlayWidget;
	
	TWeakObjectPtr<AAsgGameMode> GameMode;
	TWeakObjectPtr<UAsgGameInstance> GameInstance;

};
