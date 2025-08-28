// DU INC

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "STUBaseWidget.generated.h"

class USoundCue;

UCLASS()
class SHOUTTHEMUPBLANK_API USTUBaseWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void Show();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue *OpenSound;

protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation *ShowAnimation;
};
