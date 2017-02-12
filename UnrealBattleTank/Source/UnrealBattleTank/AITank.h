// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AITank.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class UNREALBATTLETANK_API AAITank : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void Tick(float DeltaSeconds) override;
};
