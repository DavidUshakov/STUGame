// DU INC

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "STUSpectatorWidget.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API USTUSpectatorWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    bool GetRespawnTime(int32 &CountDownTime) const;
};
