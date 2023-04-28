// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "TDMacros.h"
#include "AttributesSets/TDHealthAttributeSet.h"
#include "AttributesSets/TDDamageAttributeSet.h"
#include "AttributesSets/TDLevelAttributeSet.h"
#include "TDDamageEnemyCalculation.generated.h"

/**
 *
 */

struct TDAttributeCaptureDamageEnemy
{
    TDDECLARE_ATTRIBUTE_CAPTUREDEF(health, Target);
    TDDECLARE_ATTRIBUTE_CAPTUREDEF(attackDamage, Source);
    TDDECLARE_ATTRIBUTE_CAPTUREDEF(level, Source);

    TDAttributeCaptureDamageEnemy()
    {
        TDDEFINE_ATTRIBUTE_CAPTUREDEF(UTDHealthAttributeSet, health, Target, false);
        TDDEFINE_ATTRIBUTE_CAPTUREDEF(UTDDamageAttributeSet, attackDamage, Source, false);
        TDDEFINE_ATTRIBUTE_CAPTUREDEF(UTDLevelAttributeSet, level, Source, false);
    }
};



UCLASS()
class TOWERDEFENSE_API UTDDamageEnemyCalculation : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()

public:

    UTDDamageEnemyCalculation();

public:

protected:

private:

    TDAttributeCaptureDamageEnemy structAbilities;

public:

protected:

    virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;


private:
};