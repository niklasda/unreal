// Copyright 2020 nida


#include "OpenDoor.h"

//#include "GameFramework/Actor.h"

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
	//TargetYaw = CurrentRotation.Yaw-90;
	TargetYaw += StartYaw;

	if (!PressurePlate)
	{

		// actorname has open door component but no pressure plate set

		//const FString Name = GetOwner()->GetName();

		UE_LOG(LogTemp, Error, TEXT("%s has OpenDoor component but no PressurePlate"), *GetOwner()->GetName());

	}
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor(DeltaTime);
	}

	// ...
}

// Called every frame
void UOpenDoor::OpenDoor(float DeltaTime)
{

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.1f);

	UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f - %f"), StartYaw, CurrentYaw, TargetYaw, DeltaTime);


	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(DoorRotation);

}
