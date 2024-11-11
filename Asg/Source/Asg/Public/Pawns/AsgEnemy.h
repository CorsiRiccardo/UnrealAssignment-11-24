// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AsgPawnBase.h"
#include "AsgEnemy.generated.h"

class UAsgEnemyDa;

UCLASS(Blueprintable)
class ASG_API AAsgEnemy : public AAsgPawnBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UAsgEnemyDa> EnemyData;
};
