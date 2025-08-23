// DU INC

#pragma once

#include "CoreMinimal.h"
#include "STUBaseCharacter.h"

#include "STUAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUAICharacter : public ASTUBaseCharacter
{
    GENERATED_BODY()

public:

    ASTUAICharacter(const FObjectInitializer &ObjInit);

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    UBehaviorTree *BehaviorTreeAsset;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
    float HealthVisibilityDistance = 1000.0f;

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UWidgetComponent *HealthWidgetComponent;

    virtual void BeginPlay() override; 
    virtual void OnDeath() override;
    virtual void OnHealthChanged(float Health, float HealthDelta) override;

private:
    void UpdateHealthWidgetVisibility();
};
