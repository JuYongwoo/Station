// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AGhost.generated.h"

UCLASS()
class STATION_API AAGhost : public ACharacter
{
	GENERATED_BODY()

public:
    AAGhost();

protected:
    virtual void BeginPlay() override;


};
