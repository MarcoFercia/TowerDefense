// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/TDInterface.h"
#include "TDTower.generated.h"

UCLASS()
class TOWERDEFENSE_API ATDTower : public AActor, public ITDInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATDTower();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
        int TGGApplyEffect_Implementation();

};
