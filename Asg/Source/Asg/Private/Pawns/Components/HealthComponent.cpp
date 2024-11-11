// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Components/HealthComponent.h"

#include "Pawns/AsgPawnBase.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if(const auto CastedOwner = Cast<AAsgPawnBase>(GetOwner()); IsValid(CastedOwner))
	{
		MaxHealth = CastedOwner->GetMaxHealth().GetValue();
		CurrentHealth = MaxHealth;
	}
}

void UHealthComponent::AddHealth(const float InHealth)
{
	CurrentHealth += FMath::Clamp(InHealth,0,MaxHealth);
}

