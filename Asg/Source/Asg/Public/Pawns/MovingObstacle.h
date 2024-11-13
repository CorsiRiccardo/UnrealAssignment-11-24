// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObstacle.generated.h"

class UBoxComponent;
class UFloatingPawnMovement;
class USphereComponent;

UCLASS()
class ASG_API AMovingObstacle : public APawn
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	// Sets default values for this actor's properties
	AMovingObstacle();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBoxComponent> BoxComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* FloatingPawnMovement = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FVector MovementDirection = -FVector::RightVector;
	
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
