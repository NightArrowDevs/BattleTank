// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "Tank.h"
#include "AITank.h"

void AAITank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AITank = Cast<ATank>(GetPawn());
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto PlayerController = Cast<ATank>(PlayerPawn);
	AITank->AimAt(PlayerController->GetActorLocation());
	AITank->Fire();
}





