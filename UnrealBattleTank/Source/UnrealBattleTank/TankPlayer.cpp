// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankPlayer.h"

ATank* ATankPlayer::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); 
	// Goes to the actor/pawn/character and gets the actor/pawn/character
}


