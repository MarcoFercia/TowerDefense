// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDRoundManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class TOWERDEFENSE_API ATDRoundManager : public AActor
{
	GENERATED_BODY()


private:

	ATDRoundManager();

	~ATDRoundManager();

public:




protected:



	

private:

	int32 killedWegith = 0;

	int32 RoundWeight = 0;

	int32 actualRound = 4;

	float timeRound = 0;

	float timeperSpawn = 0.7f;

	static ATDRoundManager* managerRef;

	bool isSawning = false;

public:
	UFUNCTION(BlueprintCallable)
	void TDStartRound();

    UFUNCTION(BlueprintCallable)
        void TDStopRound();

	static ATDRoundManager* TDGetRoundManager();

	virtual void Tick(float DeltaSeconds) override;


	void TDEnemyKillWeight(int32& _weight);


protected:

	virtual void BeginPlay() override;

private:

};
