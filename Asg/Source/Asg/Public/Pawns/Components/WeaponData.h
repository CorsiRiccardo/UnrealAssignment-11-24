// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

class AProjectileBullet;
/**
 * 
 */
UCLASS()
class ASG_API UWeaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	float CooldownTime = 0.5;
	
	UPROPERTY(EditAnywhere)
	float Velocity = 50;

	UPROPERTY(EditAnywhere)
	float DistanceFromPawn = 200;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectileBullet> ProjectileBulletClass;
};
