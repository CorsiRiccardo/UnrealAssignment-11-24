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
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth = 0;

	UPROPERTY(VisibleAnywhere)
	float MaxHealth = 0;

	UPROPERTY(VisibleAnywhere)
	float RegenTime = 0;

	UPROPERTY(VisibleAnywhere)
	float RegenAmount = 0;

	FTimerHandle HealthRegenTimerHandle;

	bool bCanRegen = true;
	float LastRegenElapsedTime = 0;
	
	void StartRegenTimer();
	void RegenTimerFinished();
public:
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, int32, Health);
	FOnHealthChanged OnHealthChanged;
	
	//Returns updated health
	UFUNCTION(BlueprintCallable)
	float AddHealth(float InHealth);

};
