#pragma once

#include "CoreMinimal.h"
#include "UI/Utilities/TDButton.h"
#include "TDButtonMap.generated.h"

UCLASS()
class TOWERDEFENSE_API UTDButtonMap : public UTDButton
{
    GENERATED_BODY()
public:
    virtual bool Initialize() override;
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

public:

protected:


private:
    UPROPERTY()
        TSoftObjectPtr<UWorld> levelReference;


public:
    UFUNCTION(BlueprintCallable)
        void TDSetLevelReference(TSoftObjectPtr<UWorld> _levelReference);

    UFUNCTION(BlueprintPure)
        TSoftObjectPtr<UWorld> TDGetLevelReference() const;

    UFUNCTION()
        void TDOpenLevel();



protected:


private:


};
