// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/TDCharacter.h"
#include "TDPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ATDPlayerCharacter : public ATDCharacter
{
	GENERATED_BODY()
	
public:

	ATDPlayerCharacter();


 
public:


    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability System")
        UDataTable* statsDatatable;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability System")
        TArray<TSubclassOf<UGameplayAbility>> abiliyList;




protected:



private:





public:

    virtual void Tick(float DeltaTime) override;

protected:

    virtual void BeginPlay() override;

private:

   

};
