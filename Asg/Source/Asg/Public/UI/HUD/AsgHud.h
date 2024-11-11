// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AsgHud.generated.h"

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

private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAsgUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UAsgUserWidget> OverlayWidget;

};
