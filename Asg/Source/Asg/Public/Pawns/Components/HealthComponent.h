// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASG_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth = 0;

	UPROPERTY(VisibleAnywhere)
	float MaxHealth = 0;	
public:

	//Returns updated health
	UFUNCTION(BlueprintCallable)
	float AddHealth(float InHealth);

};
