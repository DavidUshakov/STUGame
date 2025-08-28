// DU INC

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"

#include "STUNeedAmmo.generated.h"

class ASTUBaseWeapon;
class ASTULauncherWeapon;

UCLASS()
class SHOUTTHEMUPBLANK_API USTUNeedAmmo : public UBTDecorator
{
    GENERATED_BODY()

public:
    USTUNeedAmmo();

protected:
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    TSubclassOf<ASTUBaseWeapon> WeaponType;
};
