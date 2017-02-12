// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject // Adding the component
		<UProjectileMovementComponent> // Select the component
		(FName("ProjectileMovementComponent")); // Name of the component
	ProjectileMovement->bAutoActivate = false; // We set this off
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LaunchProjectile(float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Tank fired projectile"));
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed); // Setting up the projectile movement
	ProjectileMovement->Activate(); // Activate the projectile movement
}
