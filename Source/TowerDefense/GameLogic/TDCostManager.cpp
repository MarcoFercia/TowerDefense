// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLogic/TDCostManager.h"

ATDCostManager::ATDCostManager()
{
    TowerBuyCost.Add(ELootItems::BalisticBP, FBuyCost());
    TowerBuyCost.Add(ELootItems::SonicBP, FBuyCost());
    TowerBuyCost.Add(ELootItems::DeathRayBP, FBuyCost());
    TowerBuyCost.Add(ELootItems::SpeedTowerBP, FBuyCost());
    TowerBuyCost.Add(ELootItems::AttackTowerBP, FBuyCost());
}

void ATDCostManager::TDCalculateTowerBuyCost_Implementation(FBuyCost& _cost, ELootItems _Item)
{
    _cost = TowerBuyCost[_Item];
}

bool ATDCostManager::TDCanAffordBuy(FBuyCost& _cost, ELootItems _Item)
{
    if (_cost.scrapCost == 0 && _cost.BPCost == 0)
    {
        return false;
    }

    TMap<ELootItems, int32> PlayerInventory;
    PlayerInventory = UTDGameData::TDGetPlayerRef()->TDGetPlayerInventory();


    int32 PlayerScrap = PlayerInventory[ELootItems::Scrap];
    int32 PlayerBP = PlayerInventory[_Item];


    if (PlayerScrap >= _cost.scrapCost && PlayerBP >= _cost.BPCost)
    {
        return true;
    }

    return false;
}

bool ATDCostManager::TDCanAffordElementChange(FBuyCost& _cost, ELootItems _Item)
{

    if (_cost.GemCost == 0)
    {
        return false;
    }

    int32 gemNumber = UTDGameData::TDGetPlayerRef()->TDGetAmountItemByItem(_Item);

    if (gemNumber >= _cost.GemCost)
    {
        return true;
    }


    return false;
}

void ATDCostManager::TDCalculateUpgradeCost_Implementation(FBuyCost& _cost, ELootItems _Item, int32 _actualLevel)
{


    if (_Item == ELootItems::Plasma || _Item == ELootItems::Ice || _Item == ELootItems::Fire)
    {
        _cost = FBuyCost();
        return;
    }

    _cost.scrapCost = 3 + (_actualLevel - 1);
    _cost.BPCost = 1 + ((_actualLevel - 1) / 10);


}

void ATDCostManager::TDCalculateElementChange_Implementation(FBuyCost& _cost, EElements _Element, EElements _actualElement)
{

    if (_Element == _actualElement)
    {
        _cost = FBuyCost();
        return;
    }

    _cost.GemCost = 1;
}

