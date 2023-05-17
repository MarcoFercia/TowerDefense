// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TDPlayerCharacter.h"
#include "GameLogic/TDGameData.h"
#include "GameLogic/TDRoundManager.h"

ATDPlayerCharacter::ATDPlayerCharacter()
{


    SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>("SwordMesh");
    SwordMesh->SetupAttachment(GetMesh(), "WeaponSocketHero");

    PlayerInventory.Add(ELootItems::Scrap, 0);
    PlayerInventory.Add(ELootItems::SwordBP, 0);
    PlayerInventory.Add(ELootItems::ArmorBP, 0);
    PlayerInventory.Add(ELootItems::BootsBP, 0);
    PlayerInventory.Add(ELootItems::BalisticBP, 0);
    PlayerInventory.Add(ELootItems::SonicBP, 0);
    PlayerInventory.Add(ELootItems::DeathRayBP, 0);
    PlayerInventory.Add(ELootItems::SpeedTowerBP, 0);
    PlayerInventory.Add(ELootItems::AttackTowerBP, 0);
    PlayerInventory.Add(ELootItems::Fire, 0);
    PlayerInventory.Add(ELootItems::Ice, 0);
    PlayerInventory.Add(ELootItems::Plasma, 0);


}

void ATDPlayerCharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    UTDGameData::TDSetPlayerRef(this);

}

void ATDPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


}

void ATDPlayerCharacter::TDUpdateRoundValues(int32 _Rounds)
{
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player Update"));
}

int32 ATDPlayerCharacter::TDGetAmountItemByItem(ELootItems _item)
{
    return PlayerInventory[_item];
}

int32 ATDPlayerCharacter::TDAddItemToInventory(ELootItems _item, int32 _amount /*= 1*/)
{
    uint32 temp = 0;
    if (PlayerInventory.Contains(_item))
    {
         temp = PlayerInventory[_item];
         temp += _amount;
         PlayerInventory.Add(_item, temp);
    }   
    return temp;
}

void ATDPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    TDInitialize();
    UTDGameData::TDGetRoundManager()->FOnBuyPhaseStartDelegate.AddDynamic(this, &ATDPlayerCharacter::TDUpdateRoundValues);
}


void ATDPlayerCharacter::TDInitialize()
{
    Super::TDInitialize();

    const UAttributeSet* attributesInit1 = abilitySystem->InitStats(UTDHealthAttributeSet::StaticClass(), healthDatatable);
    healthAttributes = Cast<UTDHealthAttributeSet>(attributesInit1);

    const UAttributeSet* attributesInit2 = abilitySystem->InitStats(UTDDamageAttributeSet::StaticClass(), damageDatatable);
    damageAttributes = Cast<UTDDamageAttributeSet>(attributesInit2);

    const UAttributeSet* attributesInit3 = abilitySystem->InitStats(UTDMovementAttributeSet::StaticClass(), movementDatatable);
    movementAttributes = Cast<UTDMovementAttributeSet>(attributesInit3);

    for (size_t i = 0; i < abiliyList.Num(); ++i)
    {
        FGameplayAbilitySpecHandle specHandle = abilitySystem->GiveAbility(FGameplayAbilitySpec(abiliyList[i].GetDefaultObject(), 1, 0));
    }
    GetCharacterMovement()->MaxWalkSpeed = movementAttributes->GetmovementSpeed();

    TDActivateDelegates();
}


