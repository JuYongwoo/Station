// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "PickupActor.generated.h"

UCLASS()
class STATION_API APickupActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
    APickupActor();

    virtual FText GetInteractionText_Implementation() const;
    virtual void Interact_Implementation(AActor* Interactor);

    UPROPERTY(EditAnywhere)
    FString ItemID = TEXT("2");
};
