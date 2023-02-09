// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TGInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UTGInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TOWERDEFENSE_API ITGInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:


	//Este se puede implementar en BP y en C++
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
         int TGGApplyEffect();



	//Este solo se puede implementar en BP
//     UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
//         const bool TGGApplyEffect2() const;






};
