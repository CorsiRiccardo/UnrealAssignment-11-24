// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/AsgPawnDABase.h"
#include "GameFramework/Pawn.h"
#include "AsgPawnBase.generated.h"

class UHealthComponent;
class UCombatComponent;
class UFloatingPawnMovement;
class UAsgPawnDABase;
class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

UCLASS(Abstract)
class ASG_API AAsgPawnBase : public APawn
{
	GENERATED_BODY()

public:
	AAsgPawnBase();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	TObjectPtr<UAsgPawnDABase> Data;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* FloatingPawnMovement;
	
	UPROPERTY(VisibleAnywhere)
	UCombatComponent* CombatComponent;

	UPROPERTY(VisibleAnywhere)
	UHealthComponent* HealthComponent;

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	TOptional<float> GetMovementSpeed() const { return Data ? Data->MovementSpeed : -1; };
	TOptional<float> GetMaxHealth() const { return Data ? Data->MaxHealth : -1; };
	UCombatComponent* GetCombatComponent() const { return CombatComponent; };
};
