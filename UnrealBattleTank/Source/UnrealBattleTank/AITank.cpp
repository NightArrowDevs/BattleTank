// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "AITank.h"

void AAITank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void AAITank::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAIControlledTank();
	if (AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Getting ai controlled tank of %s"),*(AITank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't get ai controlled tank"));
	}
	
	auto PlayerController = GetPlayerController();
	if (PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Getting player controller of %s"), *(PlayerController->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't get player controller"));
	}
}

ATank* AAITank::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* AAITank::GetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}

void AAITank::AimTowardsCrosshair()
{
	FVector HitLocation; // OUT parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		// Get world location if linetrace through crosshair
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// If it hits the landscape
			// Tell controlled tank to aim at this point
	}
}

bool AAITank::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}


