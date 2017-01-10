// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankPlayer.h"

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


