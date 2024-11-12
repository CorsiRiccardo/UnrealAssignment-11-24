// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/Components/HealthComponent.h"

#include "Pawns/AsgPawnBase.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if(const auto CastedOwner = Cast<AAsgPawnBase>(GetOwner()); IsValid(CastedOwner))
	{
		MaxHealth = CastedOwner->GetMaxHealth().GetValue();
		CurrentHealth = MaxHealth;
		RegenTime = CastedOwner->GetRegenTime().GetValue();
		RegenAmount = CastedOwner->GetRegenAmount().GetValue();
	}
}

void UHealthComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(bCanRegen)
	{
		LastRegenElapsedTime += DeltaTime;
		if(LastRegenElapsedTime >= RegenTime)
		{
			LastRegenElapsedTime = 0;
			AddHealth(RegenAmount);
		}
	}
}

void UHealthComponent::StartRegenTimer()
{
	GetOwner()->GetWorldTimerManager().SetTimer(
		HealthRegenTimerHandle,
		this,
		&UHealthComponent::RegenTimerFinished,
		RegenTime);
}

void UHealthComponent::RegenTimerFinished()
{
	LastRegenElapsedTime = RegenTime;
	bCanRegen = true;
}

float UHealthComponent::AddHealth(const float InHealth)
{
	if(InHealth < 0)
	{
		bCanRegen = false;
		StartRegenTimer();
	}
	CurrentHealth = FMath::Clamp(CurrentHealth + InHealth,0,MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth);
	return CurrentHealth;
}

