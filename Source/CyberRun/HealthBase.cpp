// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBase.h"

// Sets default values for this component's properties
UHealthBase::UHealthBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;

	// ...
	
}


// Called every frame
void UHealthBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthBase::LoseHealth(float Amount)
{
	CurrentHealth -= Amount;
	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
	}
}

void UHealthBase::GainHealth(float Amount)
{
	CurrentHealth += Amount;
	if (CurrentHealth >= MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

