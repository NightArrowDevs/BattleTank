// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "AITank.h"

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
}

ATank* AAITank::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

