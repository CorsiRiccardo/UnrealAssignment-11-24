// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AsgPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class ASG_API AAsgPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;
private:

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AsgInputMappingContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> ShootAction;
	
	void Move(const FInputActionValue& InputActionValue);
	void Shoot();
	void CursorTrace() const;
};
