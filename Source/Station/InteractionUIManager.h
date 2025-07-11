// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionUIManager.generated.h"

UCLASS(Blueprintable)
class STATION_API UInteractionUIManager : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ShowInteractionUI(const FText& InteractionText);

    UFUNCTION(BlueprintCallable, Category = "UI")
    void HideInteractionUI();

protected:
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* InteractionTextBlock;
};