// DU INC

#include "Sound/STUSoundFuncLib.h"
#include "Sound/SoundClass.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUSoundFuncLib, All, All);

void USTUSoundFuncLib::SetSoundClassVolume(USoundClass *SoundClass, float volume)
{
    if (!SoundClass)
    {
        return;
    }

    SoundClass->Properties.Volume = FMath::Clamp(volume, 0.0f, 1.0f);
    UE_LOG(LogSTUSoundFuncLib, Display, TEXT("Sound class volume was changed: %s = %f"), *SoundClass->GetName(),
           SoundClass->Properties.Volume)
}

void USTUSoundFuncLib::ToggleSoundClassVolume(USoundClass *SoundClass)
{
    if (!SoundClass)
    {
        return;
    }

    const auto NextVolume = SoundClass->Properties.Volume > 0.0f ? 0.0f : 1.0f;
    SetSoundClassVolume(SoundClass, NextVolume);
}

