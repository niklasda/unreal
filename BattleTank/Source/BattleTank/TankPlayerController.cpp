// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay"));

	const auto TheTank = GetControlledTank();
	if(!TheTank)
	{
		//const FString TheName = TheTank->GetName();

		UE_LOG(LogTemp, Warning, TEXT("no Tank "));
	}
	else
	{
		const FString TheName = TheTank->GetName();

		UE_LOG(LogTemp, Warning, TEXT("GetTank %s"), *TheName);
	}
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
	
	// UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticks"));

}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if( !GetControlledTank())
	{
		return;
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* TheTank = Cast<ATank>(GetPawn());

	

	
	return TheTank;
}