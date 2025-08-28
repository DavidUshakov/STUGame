// DU INC

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "STUFireBTService.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API USTUFireBTService : public UBTService
{
    GENERATED_BODY()

public:
    USTUFireBTService();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;
};
