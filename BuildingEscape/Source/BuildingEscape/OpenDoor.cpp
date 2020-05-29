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

	//float MyFloat = 10.f;




}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	const float CurrentYaw = CurrentRotation.Yaw;

	//TargetYaw
	
	//UE_LOG(LogTemp, Warning, TEXT("%f"), yaw);

	const float NewYaw = FMath::Lerp(CurrentYaw, TargetYaw , 0.01f);
	
	//CurrentRotation.Yaw = NewYaw;


	UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f"), CurrentYaw, TargetYaw, NewYaw);

	//FRotator OpenDoor1 = { 0.f, -90, 0.f };
	//FRotator OpenDoor2{ 0.f, -90, 0.f };
	//FRotator OpenDoor3(0.f, -90, 0.f);

	GetOwner()->SetActorRotation(CurrentRotation.Add(0, NewYaw-CurrentYaw, 0));


	// ...
}

