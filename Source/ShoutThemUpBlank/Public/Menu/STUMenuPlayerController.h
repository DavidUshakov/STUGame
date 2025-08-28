// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "STUMenuPlayerController.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUMenuPlayerController : public APlayerController
{
    GENERATED_BODY()

protected:

    virtual void BeginPlay() override;
};
