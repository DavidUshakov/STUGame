// DU INC

#pragma once

#include "BehaviorTree/BTDecorator.h"
#include "CoreMinimal.h"

#include "STUHealthPercentDecorator.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API USTUHealthPercentDecorator : public UBTDecorator
{
    GENERATED_BODY()

public:
    USTUHealthPercentDecorator();

protected:
    virtual bool CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float HealthPercent = 0.6f;

};
