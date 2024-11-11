// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Player/AsgPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Asg/Public/Pawns/AsgPawnBase.h"

void AAsgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AsgInputMappingContext);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(AsgInputMappingContext,0);
	}
}

void AAsgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAsgPlayerController::Move);
	EnhancedInputComponent->BindAction(ShootAction,ETriggerEvent::Triggered,this,&AAsgPlayerController::Shoot);

}

void AAsgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation (0, Rotation.Yaw,0);

	const FVector FwdDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if(const auto ControlledPawn = GetPawn<APawn>())
	{
		if(const auto CastedControlledPawn = Cast<AAsgPawnBase>(ControlledPawn))
		{
			TOptional<float> PawnMoveSpeed = CastedControlledPawn->GetMovementSpeed();
			
			ensure(PawnMoveSpeed.IsSet());

			const float MultFactor = PawnMoveSpeed.GetValue();
			
			ControlledPawn->AddMovementInput(FwdDir,InputAxisVector.Y * MultFactor);
			ControlledPawn->AddMovementInput(RightDir,InputAxisVector.X * MultFactor);
		}else
		{
			ControlledPawn->AddMovementInput(FwdDir,InputAxisVector.Y);
			ControlledPawn->AddMovementInput(RightDir,InputAxisVector.X);
		}
	}
}

void AAsgPlayerController::Shoot()
{
}

void AAsgPlayerController::CursorTrace()
{
}
