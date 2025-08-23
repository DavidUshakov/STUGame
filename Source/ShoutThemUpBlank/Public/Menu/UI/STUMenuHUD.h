// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "STUMenuHUD.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUMenuHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> MenuWidgetClass;

    virtual void BeginPlay() override;
};
