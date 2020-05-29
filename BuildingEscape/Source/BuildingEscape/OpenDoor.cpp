// Copyright 2020 nida


#include "OpenDoor.h"

#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	const FRotator CurrentRotation = GetOwner()->GetActorRotation();

	StartYaw = CurrentRotation.Yaw;
	CurrentYaw = StartYaw;
	TargetYaw = CurrentRotation.Yaw-90;

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); 


	//CurrentYaw = CurrentRotation.Yaw;

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.02f);
	//const float NewYaw2 = FMath::FInterpConstantTo(CurrentYaw, TargetYaw, DeltaTime, 45);
	//CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
	
	UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f"),  StartYaw, CurrentYaw, TargetYaw);

	// FRotator OpenDoor1 = { 0.f, -90, 0.f };  
	// FRotator OpenDoor2{ 0.f, -90, 0.f }; 
	// FRotator OpenDoor3(0.f, -90, 0.f);

	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	
	GetOwner()->SetActorRotation(DoorRotation) ;
	 
	// ...
}

 