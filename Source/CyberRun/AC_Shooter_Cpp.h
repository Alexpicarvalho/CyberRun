// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AC_Shooter_Cpp.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYBERRUN_API UAC_Shooter_Cpp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_Shooter_Cpp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting Settings")
	int ShotsPerSecond = 100;

	float TimeSinceLastShot = 99;
	float TimeBetweenShots;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void UpdateValues(const float DeltaTime);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void Fire();

		
};
