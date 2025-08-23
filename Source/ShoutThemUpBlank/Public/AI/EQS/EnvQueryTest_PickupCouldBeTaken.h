// DU INC

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"

#include "EnvQueryTest_PickupCouldBeTaken.generated.h"

UCLASS()
class SHOUTTHEMUPBLANK_API UEnvQueryTest_PickupCouldBeTaken : public UEnvQueryTest
{
    GENERATED_BODY()

public:
    explicit UEnvQueryTest_PickupCouldBeTaken(const FObjectInitializer &ObjectInitializer);

    virtual void RunTest(FEnvQueryInstance &QueryInstance) const override;

};
