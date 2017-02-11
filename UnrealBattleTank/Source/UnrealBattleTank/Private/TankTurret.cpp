// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankTurret.h"

void UTankTurret::RotatingTurret(float RelativeSpeedTurret)
{
	auto RelativeTurret = FMath::Clamp(RelativeSpeedTurret, -1.f, 1.f);
	auto RotateTurretChange = RelativeTurret * TurretDegreePerSec * GetWorld()->DeltaTimeSeconds;
	auto RawRotateTurretChange = RotateTurretChange + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0, RawRotateTurretChange, 0));

}

