// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/TDInterface.h"
#include "AbilitySystemInterface.h"
#include "TDTower.generated.h"

class UTDTowerAttributeSet;
class UDataTable;
struct FOnAttributeChangeData;




UCLASS()
class TOWERDEFENSE_API ATDTower : public AActor, public ITDInterface, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATDTower();

public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability System")
        UDataTable* statsDatatable;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability System")
        TArray<TSubclassOf<class UGameplayAbility>> abiliyList;

protected:


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System", meta = (AllowPrivateAccess = "true")) // @TODO: No aparece el inspector
        UAbilitySystemComponent* abilitySystem;


#pragma region DELEGATES

    
    FDelegateHandle TowerRangeChangedDelegateHandle;
    FDelegateHandle TowerDamageChangedDelegateHandle;
    FDelegateHandle TowerPeriodAttackChangedDelegateHandle;
#pragma endregion



 

private:

    UPROPERTY()
    float timer;

    UPROPERTY()
    float periodAttack;

    UPROPERTY(Transient)
        const UTDTowerAttributeSet* TowerAttributes;






    UFUNCTION(BlueprintCallable)
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
        int TGGApplyEffect_Implementation();



protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;



private:

    void TDInitialize();

    void TDActivateDelegates();


    void TDDamageChanged(const FOnAttributeChangeData& Data);

    void TDRangeChanged(const FOnAttributeChangeData& Data);

    void TDPeriodAttackChanged(const FOnAttributeChangeData& Data);


};
