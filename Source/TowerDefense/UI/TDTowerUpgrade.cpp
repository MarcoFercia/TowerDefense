// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TDTowerUpgrade.h"
#include "Map/TDTower.h"
#include "GameLogic/TDElementComponent.h"
#include "GameLogic/ElementsEnum.h"
#include <GameplayEffect.h>
#include "AttributesSets/TDLevelAttributeSet.h"
#include "Components/TDWidgetShopComponent.h"
#include "Utilities/TDComposedButton.h"
#include "Utilities/TDBaseButton.h"


bool UTDTowerUpgrade::Initialize()
{
    Super::Initialize();

    return true;
}

void UTDTowerUpgrade::NativePreConstruct()
{
    Super::NativePreConstruct();


}

void UTDTowerUpgrade::NativeConstruct()
{
    Super::NativeConstruct();

    plasmaUpgrade->imgButton->OnClicked.AddDynamic(this, &UTDTowerUpgrade::TDPlasmaUpgrade);
    fireUpgrade->imgButton->OnClicked.AddDynamic(this, &UTDTowerUpgrade::TDFireUpgrade);
    iceUpgrade->imgButton->OnClicked.AddDynamic(this, &UTDTowerUpgrade::TDIceUpgrade);
    levelUp->imgButton->OnClicked.AddDynamic(this, &UTDTowerUpgrade::TDLevelUp);
    exit->OnClicked.AddDynamic(this, &UTDTowerUpgrade::TDCloseUI);
}

void UTDTowerUpgrade::TDPlasmaUpgrade()
{
    TDSetElement(EElements::Plasma);
}

void UTDTowerUpgrade::TDFireUpgrade()
{
    TDSetElement(EElements::Fire);
}

void UTDTowerUpgrade::TDIceUpgrade()
{
    TDSetElement(EElements::Freeze);
}

void UTDTowerUpgrade::TDLevelUp()
{
    UGameplayEffect* staticEffect = NewObject<UGameplayEffect>();
    staticEffect->Modifiers.Empty();
    FGameplayModifierInfo modif = FGameplayModifierInfo();
    modif.ModifierOp = EGameplayModOp::Additive;
    modif.Attribute = UTDLevelAttributeSet::GetlevelAttribute();
    modif.ModifierMagnitude = FGameplayEffectModifierMagnitude(FScalableFloat(1));
    staticEffect->Modifiers.Add(modif);
    Cast<ATDTower>(owner->GetOwner())->GetAbilitySystemComponent()->ApplyGameplayEffectToSelf(staticEffect, 1, FGameplayEffectContextHandle());
    staticEffect->ConditionalBeginDestroy();
}

void UTDTowerUpgrade::TDCloseUI()
{
    if (owner)
    {
        owner->TDHideUI();
    }
}

void UTDTowerUpgrade::TDSetElement(EElements _element)
{
    if (owner)
    {
        UTDElementComponent* temp = ITDInterface::Execute_TDGetElementComponent(owner->GetOwner());
        temp->TDSetSpawnedElement(_element);        
    }
}