// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUCoreTypes.h"

#include "STUBaseWeapon.generated.h"

class USkeletalMeshComponent;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUBaseWeapon : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUBaseWeapon();

    virtual void StartFire();

    virtual void StopFire();

    FOnClipEmptySignature FOnClipEmpty;
    void ChangeClip();
    bool CanReload() const;
    bool IsAmmoEmpty() const;

    FWeaponUIData GetUIData() const
    {
        return UIData;
    }

    FAmmoData GetWeaponAmmoData() const
    {
        return CurrentAmmo;
    }

    bool TryToAddAmmo(int32 ClipsAmount);

    virtual void Zoom(bool Enabled);

  protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent *WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FName MuzzleSocketName = TEXT("MuzzleSocket");

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    FAmmoData DefaultAmmo{15, 10, false};

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "UI")
    FWeaponUIData UIData;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, category = "VFX")
    UNiagaraSystem *MuzzleFX;

    UNiagaraComponent *SpawnMuzzleFX();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    virtual void MakeShot();

    APlayerController *GetPlayerController() const;
    bool GetPlayerViewPoint(FVector &ViewLocation, FRotator &ViewRotation) const;
    FVector GetMuzzleWorldLocation() const;
    virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;
    void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);

    void DecreaseAmmo();
    bool IsClipEmpty() const;
    bool IsAmmoFull() const;

    void LogAmmo();
  private:
    FAmmoData CurrentAmmo;
};
