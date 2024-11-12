// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AsgPawnDABase.generated.h"

/**
 * 
 */
UCLASS()
class ASG_API UAsgPawnDABase : public UDataAsset
{
	GENERATED_BODY()

public:
	//*
	//	BASE ATTRIBUTES
	//*//
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float MovementSpeed = 500;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float MaxHealth = 100;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float RegenTime = 2;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float RegenAmount = 3;
	
};
