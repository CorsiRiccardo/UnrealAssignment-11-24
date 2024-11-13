// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Player/AsgPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Asg/Public/Pawns/AsgPawnBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pawns/Components/CombatComponent.h"

void AAsgPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AsgInputMappingContext);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(AsgInputMappingContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);

	SetInputMode(InputModeData);
}

void AAsgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	const auto EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAsgPlayerController::Move);
	EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AAsgPlayerController::Shoot);
}

void AAsgPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CursorTrace();
}

void AAsgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector FwdDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (const auto ControlledPawn = GetPawn<APawn>())
	{
		if (const auto CastedControlledPawn = Cast<AAsgPawnBase>(ControlledPawn))
		{
			ControlledPawn->AddMovementInput(FwdDir, InputAxisVector.Y);
			ControlledPawn->AddMovementInput(RightDir, InputAxisVector.X);
		}
		else
		{
			ControlledPawn->AddMovementInput(FwdDir, InputAxisVector.Y);
			ControlledPawn->AddMovementInput(RightDir, InputAxisVector.X);
		}
	}
}

void AAsgPlayerController::Shoot()
{
	if (const auto CastedControlledPawn = Cast<AAsgPawnBase>(GetPawn<APawn>()))
	{
		CastedControlledPawn->GetCombatComponent()->Shoot();
	}
}

void AAsgPlayerController::CursorTrace() const
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;
	if (const auto CastedPawn = Cast<AAsgPawnBase>(GetPawn<APawn>()))
	{
		const FVector_NetQuantize HitLocation = CursorHit.ImpactPoint;
		const FVector_NetQuantize HitLocationNormalized (HitLocation.X, HitLocation.Y, 0);

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(CastedPawn->GetSkeletalMeshComponent()->GetComponentLocation(), HitLocation);

		// const FVector Forward = GetPawn()->GetActorLocation() - HitLocationNormalized;
		// const FRotator Rot = UKismetMathLibrary::MakeRotFromXZ(Forward, FVector::UpVector);
		CastedPawn->GetSkeletalMeshComponent()->SetWorldRotation(
			FRotator(
				0,
				LookAtRotation.Yaw,
				0),
			true);
	}
}
