// DU INC

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "STUSoundFuncLib.generated.h"

class USoundClass;

UCLASS()
class SHOUTTHEMUPBLANK_API USTUSoundFuncLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    static void SetSoundClassVolume(USoundClass *SoundClass, float volume);

    UFUNCTION(BlueprintCallable)
    static void ToggleSoundClassVolume(USoundClass *SoundClass);
};
