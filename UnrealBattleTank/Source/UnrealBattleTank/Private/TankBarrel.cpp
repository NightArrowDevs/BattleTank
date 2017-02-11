// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto Relative = FMath::Clamp(RelativeSpeed, -1.f, 1.f);

	auto Time = GetWorld()->GetTimeSeconds();

	auto ElevateChange = Relative * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds; // 1 * 5 * DeltaSeconds
	auto RawElevateChange = RelativeRotation.Pitch + ElevateChange; 
	auto Elevation = FMath::Clamp(RawElevateChange, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0.f, 0.f)); // Barrel will rotate to the Pitch
}


