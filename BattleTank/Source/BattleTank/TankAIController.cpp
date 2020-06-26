// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay"));

	const auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		//const FString TheName = TheTank->GetName();

		UE_LOG(LogTemp, Warning, TEXT("no AI Tank "));
	}
	else
	{
		const FString TheName = PlayerTank->GetName();

		UE_LOG(LogTemp, Warning, TEXT("GetAITank %s"), *TheName);
	}
}



ATank* ATankAIController::GetControlledTank() const
{
	ATank* TheTank = Cast<ATank>(GetPawn());




	return TheTank;
}


ATank* ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if(!PlayerPawn)
	{
		return nullptr;
	}




	return Cast<ATank>(PlayerPawn);;
}