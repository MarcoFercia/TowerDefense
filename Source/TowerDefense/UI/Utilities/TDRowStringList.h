#pragma once

#include "CoreMinimal.h"
#include "UI/Utilities/TDRow.h"
#include "TDRowStringList.generated.h"

class UComboBoxString;

/**
 *
 */
UCLASS()
class TOWERDEFENSE_API UTDRowStringList : public UTDRow
{
    GENERATED_BODY()

public:
    virtual bool Initialize() override;
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

public:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
        UComboBoxString* stringList;

    UPROPERTY(EditAnywhere, Category = "Custom Properties")
        TArray<FString> customOptions;

protected:


private:


public:


protected:


private:


};
