#pragma once

#include "CoreMinimal.h"
#include "UI/TDUserWidget.h"
#include "TDInfiniteLevels.generated.h"

UCLASS()
class TOWERDEFENSE_API UTDInfiniteLevels : public UTDUserWidget
{
    GENERATED_BODY()
public:
    virtual bool Initialize() override;
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

public:

protected:

private:

public:

protected:

private:

};
