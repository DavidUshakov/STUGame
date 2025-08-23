// DU INC

#pragma once

#include "CoreMinimal.h"
#include "UI/STUBaseWidget.h"

#include "STUPauseWidget.generated.h"

class UButton;

UCLASS()
class SHOUTTHEMUPBLANK_API USTUPauseWidget : public USTUBaseWidget
{
    GENERATED_BODY()

public:

    protected:
    UPROPERTY(meta = (BindWidget))
    UButton *ClearPauseButton;

protected:
    virtual void NativeOnInitialized() override;


private:
    UFUNCTION() 
    void OnClearPause();
};
