// DU INC

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "STURespawnComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOUTTHEMUPBLANK_API USTURespawnComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    USTURespawnComponent();

    void Respawn(int32 RespawnTime);

    int32 GetResoawnCountDown() const
    {
        return RespawnCountdown;
    }

    bool IsRespawnInProgress() const;

private:
    FTimerHandle RespawnTimerHandle;
    int32 RespawnCountdown = 0;

    void RespawnTimerUpdate();

};
