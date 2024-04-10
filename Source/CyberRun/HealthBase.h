// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthBase.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYBERRUN_API UHealthBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthBase();

	//Events
	DECLARE_DYNAMIC_DELEGATE(FOnHealthLost);
	FOnHealthLost OnHealthLost;

	DECLARE_DYNAMIC_DELEGATE(FOnHealthGained);
	FOnHealthGained OnHealthGained;

	DECLARE_DYNAMIC_DELEGATE(FOnHealthZero);
	FOnHealthZero OnHealthZero;

	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly ,Category = "Health")
	float CurrentHealth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Health Methods")
	virtual void LoseHealth(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Health Methods")
	virtual void GainHealth(float Amount);
};
