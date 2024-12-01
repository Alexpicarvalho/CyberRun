// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_Shooter_Cpp.h"

// Sets default values for this component's properties
UAC_Shooter_Cpp::UAC_Shooter_Cpp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_Shooter_Cpp::BeginPlay()
{
	Super::BeginPlay();
	TimeBetweenShots = 1.0f / ShotsPerSecond;

	// ...
	
}

// Called every frame
void UAC_Shooter_Cpp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateValues(DeltaTime);

	// ...
}

void UAC_Shooter_Cpp::UpdateValues(const float DeltaTime)
{
		TimeSinceLastShot += DeltaTime;
}

void UAC_Shooter_Cpp::Fire()
{
	if(TimeSinceLastShot < TimeBetweenShots) return;

	TimeSinceLastShot = 0;
	GEngine -> AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fire!"));

	const APlayerCameraManager * PlayerCameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	const FVector Start = PlayerCameraManager->GetCameraLocation();
	const FVector End = Start + PlayerCameraManager->GetActorForwardVector() * 100000;

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);

	DrawDebugBox(
		GetWorld(),
		HitResult.ImpactPoint,
		FVector::One(),
		FQuat::Identity,
		FColor::Red,
		false,
		10,
		0,
		10);
}

