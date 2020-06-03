// Copyright 2020 nida


#include "Grabber.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT 

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty"));


}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	const UWorld* World = GetWorld();
	const APlayerController* Player = World->GetFirstPlayerController();

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	Player->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	//UE_LOG(LogTemp, Warning, TEXT("%s - %s"), *PlayerViewPointLocation.ToCompactString(), *PlayerViewPointRotation.ToCompactString());


	FVector RotRot = PlayerViewPointRotation.Vector();
	const FVector LineTraceEnd = PlayerViewPointLocation + RotRot * Reach;

	DrawDebugLine(World, PlayerViewPointLocation, LineTraceEnd, FColor(90, 100, 0), false, -1, 0, 5.f);

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerViewPointLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	if (Hit.IsValidBlockingHit())
	{
		AActor* a = Hit.GetActor();
		if (a)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s - %s"), *a->GetName(), *a->GetTransform().ToHumanReadableString());
		}
	}
}

