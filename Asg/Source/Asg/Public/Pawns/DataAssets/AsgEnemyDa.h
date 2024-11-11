// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AsgPawnDABase.h"
#include "AsgEnemyDa.generated.h"

/**
 * 
 */
UCLASS()
class ASG_API UAsgEnemyDa : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float AcceptableDistanceToShoot = 1000;

};
