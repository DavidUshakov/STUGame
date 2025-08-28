// DU INC

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"

#include "STULauncherWeapon.generated.h"

class ASTUProjectTile;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTULauncherWeapon : public ASTUBaseWeapon
{
    GENERATED_BODY()

public:
    virtual void StartFire() override;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    TSubclassOf<ASTUProjectTile> ProjectTileClass;

    virtual void MakeShot() override;
};
