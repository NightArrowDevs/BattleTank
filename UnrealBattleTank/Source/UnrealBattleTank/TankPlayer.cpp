// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankPlayer.h"

void ATankPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayer::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	if (GetControlledTank() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Getting controlled tank"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't get controlled tank"));
	}

}

ATank* ATankPlayer::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); 
	// Goes to the actor/pawn/character and gets the actor/pawn/character
}

void ATankPlayer::AimTowardsCrosshair()
{
	FVector HitLocation; // OUT parameter

	if (GetSightRayHitLocation(HitLocation))
	{
		// Get world location if line trace through cross hair
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// If it hits the landscape
		// Tell controlled tank to aim at this point
	}
}

bool ATankPlayer::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}

	return true;
}

bool ATankPlayer::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

