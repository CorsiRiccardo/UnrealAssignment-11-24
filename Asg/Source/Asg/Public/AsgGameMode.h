// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "AsgGameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ASG_API AAsgGameMode : public AGameMode
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	float CurrentHeight = 0;

	float CurrentCooldown = 0;
	
protected:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxHeight = 10000;

	UPROPERTY(EditDefaultsOnly)
	float HeightPerTick = 0.1;

	UPROPERTY(EditDefaultsOnly)
	float TickCooldown = 0.1;
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeightChanged,const float,NewHeight);
	FOnHeightChanged OnHeightChanged;
	
	FORCEINLINE float GetCurrentHeight() const {return CurrentHeight;}
	FORCEINLINE float GetMaxHeight() const {return MaxHeight;}
};
