// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super as we're replacing the functionality
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal(); // Tank is facing at
	auto AIForwardIntention = MoveVelocity.GetSafeNormal(); // Tank wants to go there
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention); // Dot between TankForward and AIForwardIntention
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z; // Cross between TankForward and AIForwardIntention, gets Z vector

	IntendMoveRight(RightThrow);
	IntendMoveForward(ForwardThrow); // Move forward to actor
}



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet)
	{
		return;
	}
		RightTrack = RightTrackToSet;
		LeftTrack = LeftTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}