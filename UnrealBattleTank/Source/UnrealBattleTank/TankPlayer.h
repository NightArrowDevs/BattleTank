// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h" // Tank.h is the C++ actor/pawn/character header file
#include "GameFramework/PlayerController.h"
#include "TankPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNREALBATTLETANK_API ATankPlayer : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const; 
	// ATank* is the actor/pawn/character
	// Example, header file name is "Player.h" then it is "APlayer*"
	
	virtual void BeginPlay() override;

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	virtual void Tick(float DeltaSeconds) override;

	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	
	UPROPERTY(EditAnywhere)
	float Reach = 1000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
