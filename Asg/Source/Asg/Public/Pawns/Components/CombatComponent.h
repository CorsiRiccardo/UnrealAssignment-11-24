// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pawns/AsgPawnBase.h"
#include "CombatComponent.generated.h"


class UWeaponData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASG_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	void Shoot();
protected:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UWeaponData> WeaponData;

private:
	UPROPERTY(VisibleAnywhere)
	AAsgPawnBase* OwnerPawn = nullptr;

	FTimerHandle FireTimerHandle;

	bool bCanFire = true;

	bool CanFire() const;
	void StartFireTimer();
	void FireTimerFinished();

};
