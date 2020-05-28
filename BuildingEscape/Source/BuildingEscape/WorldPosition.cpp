// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	FString Name = GetOwner()->GetName();

	//FString Log = TEXT("Hello");
	//FString* PtrLog = &Log;

	//int32 i1 = Log.Len();
	//int32 i2 = PtrLog->Len();
	//int32 i3 = (*PtrLog).Len();

	//UE_LOG(LogTemp, Warning, TEXT("Actor name: %s"), *GetOwner()->GetName());

	FString ObjectTransform = GetOwner()->GetTransform().ToHumanReadableString();
	//FString ObjectTransformLocation = GetOwner()->GetTransform().GetLocation().ToString();
	FString ObjectPosition = GetOwner()->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("Actor name: %s ObjectTransform: %s"), *Name, *ObjectTransform);
	//UE_LOG(LogTemp, Warning, TEXT("Actor ObjectTransformLocation: %s"), *ObjectTransformLocation);
	UE_LOG(LogTemp, Warning, TEXT("Actor name: %s ObjectPosition: %s"), *Name, *ObjectPosition);

}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

