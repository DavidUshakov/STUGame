// DU INC

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "GoToMenuWidget.generated.h"

class UButton;

UCLASS()
class SHOUTTHEMUPBLANK_API UGoToMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeOnInitialized() override;

    UPROPERTY(meta = (BindWidget))
    UButton *MenuButton;

private:
    UFUNCTION()
    void OnMenu();
};
