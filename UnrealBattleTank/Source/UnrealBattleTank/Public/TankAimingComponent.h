// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankTrack;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALBATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimLogging(FVector HitLocation, FString OurTankName, float LaunchSpeed);
	
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	UTankTrack* Track = nullptr;

	void BarrelRotation(FVector AimDirection);

	void TurretRotation(FVector AimDirection);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void SetTrackReference(UTankTrack* TrackToSet);
};
