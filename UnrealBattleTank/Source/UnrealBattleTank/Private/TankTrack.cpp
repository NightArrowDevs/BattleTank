// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBattleTank.h"
#include "TankTrack.h"

void UTankTrack::ThrottleRequest(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("Throttle: %f"), Throttle);
	auto ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); 
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


