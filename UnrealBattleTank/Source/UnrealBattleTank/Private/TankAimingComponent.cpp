// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimLogging(FVector HitLocation, FString OurTankName, float LaunchSpeed)
{
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // Gets to location of the socket
	const TArray<AActor*> ActorsToIgnore;

	
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity, // Use the out parameter
		StartLocation, // Start location of the projectile
		HitLocation, // End location of the projectile, in this case the hit location
		LaunchSpeed, // Launch speed of the projectile
		false, // True = High Arc, False = Low Arc
		0.f, // Not important
		0.f, // Not important
		ESuggestProjVelocityTraceOption::DoNotTrace // Not important
		)
		)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		BarrelRotation(AimDirection);
	}
}

void UTankAimingComponent::BarrelRotation(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation(); // Gets the standard rotation of barrel
	auto AimAsRotator = AimDirection.Rotation(); // Gets the aim rotation
	auto DeltaRotator = AimAsRotator - BarrelRotator; // Aim - Delta = Delta 

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

