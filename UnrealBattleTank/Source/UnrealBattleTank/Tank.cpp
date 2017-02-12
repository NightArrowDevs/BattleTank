// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject // Adding the component
	<UTankAimingComponent> // Select the component
	(FName("AimComponent")); // Name of the component
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	FString OurTankName = GetName();
	TankAimingComponent->AimLogging(HitLocation, OurTankName, LaunchSpeed); // Setting the component up
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Tank fired"));
	if (!Barrel)
	{
		return;
	}
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")), 
		Barrel->GetSocketRotation(FName("Projectile")));
}

