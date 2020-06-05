// Copyright 2020 nida

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerVolume.h"
//#include "GameFramework/Actor.h"

#include "OpenDoor.generated.h"
//#include <Runtime\Engine\Classes\Engine\TriggerVolume.h>


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	void FindAudioComponent();

	float TotalMassOfActors() const;

	float StartYaw;
	float CurrentYaw;

	float DoorLastOpened = 0.f;


	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;

	UPROPERTY(EditAnywhere)
		float DoorOpenSpeed = 0.8f;

	UPROPERTY(EditAnywhere)
		float DoorCloseSpeed = 2.f;

	UPROPERTY(EditAnywhere)
		float OpenDoorMass = 10.f;

	UPROPERTY(EditAnywhere)
		float TargetYaw;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY()
		UAudioComponent* AudioComponent = nullptr;

	//UPROPERTY(EditAnywhere)
	//	AActor* ActorThatOpens = nullptr;
};
