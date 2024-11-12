﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Asg/Public/Pawns/AsgPawnBase.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ProgressBar.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Pawns/Components/CombatComponent.h"
#include "Pawns/Components/HealthComponent.h"
#include "UI/Widgets/OverheadHealthWidget.h"


// Sets default values
AAsgPawnBase::AAsgPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Mesh->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);

	OverHeadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverHead Widget"));
	OverHeadWidget->SetupAttachment(Mesh);
	
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	CapsuleComponent->SetupAttachment(Mesh);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(Mesh);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(CameraBoom);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("Combat Component"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

// Called when the game starts or when spawned
void AAsgPawnBase::BeginPlay()
{
	Super::BeginPlay();

	checkf(Data, TEXT("No data assigned!"));
}

float AAsgPawnBase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator, AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if(HealthComponent)
	{
		const float CurrentHealth = HealthComponent->AddHealth(-ActualDamage);
		if(OverHeadWidget)
		{
			if(UOverheadHealthWidget* CastedWidget = dynamic_cast<UOverheadHealthWidget*>(OverHeadWidget);IsValid(CastedWidget))
			{
				CastedWidget->HealthProgressBar->SetPercent(CurrentHealth/Data->MaxHealth);
			}	
		}
	}
	return ActualDamage;
}

// Called every frame
void AAsgPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}