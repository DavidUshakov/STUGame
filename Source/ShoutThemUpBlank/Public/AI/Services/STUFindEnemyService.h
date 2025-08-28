// DU INC

#pragma once

#include "BehaviorTree/BTService.h"
#include "CoreMinimal.h"

#include "STUFindEnemyService.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API USTUFindEnemyService : public UBTService
{
    GENERATED_BODY()

public:
    USTUFindEnemyService();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector EnemyActorKey;

    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory,
                                       float DeltaSeconds) override;
};
