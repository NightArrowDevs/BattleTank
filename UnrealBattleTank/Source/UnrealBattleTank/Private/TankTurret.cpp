// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankTurret.h"

void UTankTurret::RotatingTurret(float RelativeSpeedTurret)
{
	auto RelativeTurret = FMath::Clamp(RelativeSpeedTurret, -1.f, 1.f);
	auto ElevateTurretChange = RelativeTurret * TurretDegreePerSec * GetWorld()->DeltaTimeSeconds;
	auto RawElevateTurretChange = ElevateTurretChange + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0, RawElevateTurretChange, 0));

}

