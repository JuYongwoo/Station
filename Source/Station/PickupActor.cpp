// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupActor.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FText APickupActor::GetInteractionText_Implementation() const
{
	return FText::FromString(TEXT("This is Item"));
}

void APickupActor::Interact_Implementation(AActor* Interactor)
{
    /*
    if (AYourCharacter* Player = Cast<AYourCharacter>(Interactor))
    {
        if (UYourInventoryComponent* Inventory = Player->FindComponentByClass<UYourInventoryComponent>())
        {
            Inventory->AddItem(ItemID);
            Destroy(); // 또는 비활성화
        }
    }
    */
}

