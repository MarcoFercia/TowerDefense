// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TDWeightManager.generated.h"

class ATDEnemy;

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UTDWeightManager : public UObject
{
	GENERATED_BODY()

private:

	UTDWeightManager();

public:

	UPROPERTY(EditAnywhere)
	int32 WeightPerRound = 1;


    UPROPERTY(EditAnywhere)
        int32 ActualRound = 9;

	TMap<int8, int32> enemiesPerClass;


protected:

private:

	static UPROPERTY(Transient) UTDWeightManager* weightManager;


    UPROPERTY(Transient)
        UDataTable* enemiesDatatable;

	UPROPERTY()
	int32 actualWegith = 0;

	UPROPERTY()
	int8 licheCounter;

	TArray<EElements> actualRoundElements;

public:

	UFUNCTION()
	static UTDWeightManager* TDGetWeightManager();


	UFUNCTION()
	void TDStartSpawn();

	UFUNCTION()
	void TDSetDataTable(UDataTable* _ref);


	UFUNCTION()
	int32 TDSetActualRound(int32& _atualRound, TArray<EElements> _roundElement);


protected:

private:


	void TDSetEnemyValues(ATDEnemy* _enemyRef);
	
};
