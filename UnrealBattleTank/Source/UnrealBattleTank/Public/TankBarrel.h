// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALBATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// -1 is down, +1 is up
	void Elevate(float RelativeSpeed); // TODO change name to "RelativeSpeed"
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
};
