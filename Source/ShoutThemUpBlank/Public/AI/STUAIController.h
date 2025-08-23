// DU INC

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"

#include "STUAIController.generated.h"

class USTUAIPerceptionComponent;
class USTURespawnComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUAIController : public AAIController
{
    GENERATED_BODY()

public:
    ASTUAIController();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTUAIPerceptionComponent *STUAIPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTURespawnComponent *STURespawnComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    FName FocusOnKeyName = "EnemyActor";

    virtual void OnPossess(APawn *InPawn) override;
    virtual void Tick(float DeltaTime) override;

private: 
    AActor *GetFocusOnActor() const;
};
