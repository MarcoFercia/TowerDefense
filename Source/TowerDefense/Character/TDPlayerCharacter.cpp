// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TDPlayerCharacter.h"
#include "GameLogic/TDGameData.h"
#include "GameLogic/TDRoundManager.h"
#include "NiagaraComponent.h"
#include "GameLogic/TDElementVFXDataAsset.h"
#include "AttributesSets/TDHealthAttributeSet.h"
#include "AttributesSets/TDDamageAttributeSet.h"
#include "AttributesSets/TDMovementAttributeSet.h"
#include <GameplayAbilitySpecHandle.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "GameLogic/TDGameMode.h"

ATDPlayerCharacter::ATDPlayerCharacter()
{


    SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>("SwordMesh");
    SwordMesh->SetupAttachment(GetMesh(), "WeaponSocketHero");

    swordCover = CreateDefaultSubobject<UNiagaraComponent>("SwordCoverNiagara");
    swordCover->SetupAttachment(GetMesh(), "VFXSwordHandle");

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



    ElementsVFX.Add(EElements::None, nullptr);
    ElementsVFX.Add(EElements::Fire, nullptr);
    ElementsVFX.Add(EElements::Freeze, nullptr);
    ElementsVFX.Add(EElements::Plasma, nullptr);


}

void ATDPlayerCharacter::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    UTDGameData::TDSetPlayerRef(this);

}



void ATDPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

    TDInitialize();
    UTDGameData::TDGetRoundManager()->FOnBuyPhaseStartDelegate.AddDynamic(this, &ATDPlayerCharacter::TDUpdateRoundValues);
    UTDGameData::TDGetGameMode()->FLootDropDelegate.AddDynamic(this, &ATDPlayerCharacter::TDAddItemToInventory);
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


    if (EffectClass)
    {
        effectRef = Cast<UGameplayEffect>(EffectClass->GetDefaultObject());
    }


    TDActivateDelegates();
}


void ATDPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


}


void ATDPlayerCharacter::TDOnElementChange_Implementation(EElements _newElement)
{
    if (ElementsVFX.Contains(_newElement))
    {
        actualVFXAsset = ElementsVFX[_newElement];
        swordCover->Activate(true);
        swordCover->SetAsset(actualVFXAsset->StaticSwordEffect);
    }
    else
    {
        actualVFXAsset = nullptr;
        swordCover->Deactivate();
    }

}


void ATDPlayerCharacter::TDUpdateRoundValues(int32 _Rounds)
{
    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player Update"));
    if (effectRef)
    {
        FGameplayEffectContextHandle context;
        abilitySystem->ApplyGameplayEffectToSelf(effectRef, 1, context);
    }


}

int32 ATDPlayerCharacter::TDGetAmountItemByItem(ELootItems _item)
{
    int32 inttemp = PlayerInventory[_item];
    return inttemp;
}

void ATDPlayerCharacter::TDAddItemToInventory(ELootItems _item, FGameplayTag _category, int32 _amount)
{
    uint32 temp = 0;
    if (PlayerInventory.Contains(_item))
    {
        //FString ObjectTypesTemp = UEnum::GetValueAsString(_item);
        //GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Green, ObjectTypesTemp);
        temp = PlayerInventory[_item];
        temp += _amount;
        PlayerInventory.Add(_item, temp);
    }
}

void ATDPlayerCharacter::TDOverrideItemInInventory(ELootItems _item, int32 _newValue)
{
    if (PlayerInventory.Contains(_item))
    {
        
        PlayerInventory.Add(_item, _newValue);
    }
}

TMap<ELootItems, int32>& ATDPlayerCharacter::TDGetPlayerInventory()
{
    return PlayerInventory;
}

UTDElementVFXDataAsset* ATDPlayerCharacter::TDGetActualElementVFXAsset()
{
    if (actualVFXAsset)
    {
        return actualVFXAsset;
    }
    return nullptr;
}




