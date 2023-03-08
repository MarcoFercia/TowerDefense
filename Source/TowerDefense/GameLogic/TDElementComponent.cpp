// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLogic/TDElementComponent.h"

// Sets default values for this component's properties
UTDElementComponent::UTDElementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTDElementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTDElementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTDElementComponent::TDSetSpawnedElement(UTDElement* _DataAsset)
{
	SpawnedElementData = _DataAsset;
	ownerElement = SpawnedElementData->ownerElement;
}

void UTDElementComponent::TDSetTemporalElement(UTDElement* _DataAsset)
{
	TemporalElementData = _DataAsset;
    ownerElement = TemporalElementData->ownerElement;

}

void UTDElementComponent::TDRemoveTemporalElement()
{
	TemporalElementData = nullptr;
	ownerElement = SpawnedElementData->ownerElement;
}

EElements UTDElementComponent::TDGetOwnerElement()
{
	return ownerElement;
}

UTDElement* UTDElementComponent::TDGetActualDataAsset()
{
	if (TemporalElementData)
	{
		return TemporalElementData;
	}
	return SpawnedElementData;
}
