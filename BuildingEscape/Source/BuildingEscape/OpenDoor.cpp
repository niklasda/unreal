// Copyright 2020 nida

#include "OpenDoor.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/AudioComponent.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
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
		UE_LOG(LogTemp, Error, TEXT("%s has OpenDoor component but no PressurePlate"), *GetOwner()->GetName());
	}

	FindAudioComponent();
	
	//const UWorld* World = GetWorld();
	//const APlayerController* Player = GetWorld()->GetFirstPlayerController();
	AActor* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	//ActorThatOpens = Pawn;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalMassOfActors() > OpenDoorMass)
	{
		
			OpenDoor(DeltaTime);
			DoorLastOpened = GetWorld()->GetTimeSeconds();
		//	DoorIsOpen = true;
		
	}
	else
	{
		if ((GetWorld()->GetTimeSeconds() > (DoorLastOpened + DoorCloseDelay)) && (DoorLastOpened > 1))
		{
		//	if (!DoorIsOpen)
			//{
				CloseDoor(DeltaTime);
			//	DoorIsOpen = false;
			//}
		}
	}
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;

	if (PressurePlate)
	{
		PressurePlate->GetOverlappingActors(OUT OverlappingActors);

		for (AActor* Actor : OverlappingActors)
		{
			UPrimitiveComponent* Phys = Actor->FindComponentByClass<UPrimitiveComponent>();
			if (Phys)
			{
				TotalMass += Phys->GetMass();
			}
			//UE_LOG(LogTemp, Error, TEXT("%s TotalMass = %f "), *Actor->GetName(),  TotalMass);

		}
	}
	

	return TotalMass;
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * DoorOpenSpeed);

	UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f - %f"), StartYaw, CurrentYaw, TargetYaw, DeltaTime);

	if (AudioComponent && !DoorIsOpen)
	{
		AudioComponent->Play();
		DoorIsOpen = true;
	}

	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(DoorRotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, StartYaw, DeltaTime * DoorCloseSpeed);

	//UE_LOG(LogTemp, Warning, TEXT("%f, %f, %f - %f"), StartYaw, CurrentYaw, TargetYaw, DeltaTime);

	if (AudioComponent && DoorIsOpen)
	{
		AudioComponent->Play();
		DoorIsOpen = false;
	}
	
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(DoorRotation);
}

void UOpenDoor::FindAudioComponent() 
{
	UAudioComponent* Sound = GetOwner()->FindComponentByClass<UAudioComponent>();

	if(!Sound)
	{
		UE_LOG(LogTemp, Error, TEXT("No sound found"));
	}
	
	AudioComponent = Sound;


	//return Sound;
}