// DU INC

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "ChangeWeaponService.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API UChangeWeaponService : public UBTService
{
    GENERATED_BODY()

public:
    UChangeWeaponService();

protected:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Probability = 0.5f;

    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
