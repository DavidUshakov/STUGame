// DU INC

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"

#include "STUWeaponComponent.generated.h"

class ASTUBaseWeapon;

UCLASS()
class SHOUTTHEMUPBLANK_API USTUWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    USTUWeaponComponent();

    virtual void StartFire();
    void StopFire();
    virtual void NextWeapon();
    void Reload();

    bool GetWeaponUIData(FWeaponUIData &UIData) const;

    bool GetWeaponAmmoData(FAmmoData &AmmoData) const;

    bool TryToAddAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType, int32 ClipsAmount);

    bool NeedAmmo(TSubclassOf<ASTUBaseWeapon> WeaponType);

    void Zoom(bool Enabled);

  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    
    bool CanFire() const;
    bool CanEquip() const;
    void EquipWeapon(int32 WeaponIndex);

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TArray<FWeaponData> WeaponData;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponEquipSocketName = "WeaponSocket";

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponArmorySocketName = "ArmorySocket";

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage *EquipAnimMontage = nullptr;

    UPROPERTY()
    ASTUBaseWeapon *CurrentWeapon = nullptr;

    UPROPERTY()
    TArray<ASTUBaseWeapon *> Weapons;
    int32 CurrentWeaponIndex = 0;

  private:
    bool EquipAnimInProgress = false;
    bool ReloadAnimInProgress = false;

    UPROPERTY()
    UAnimMontage *CurrentReloadAnimMontage = nullptr;

private:
    void SpawnWeapons();
    void AttachWeaponToSocket(ASTUBaseWeapon *Weapon, USceneComponent *SceneComponent,
                                                 const FName &SocketName);

    void PlayAnimMontage(UAnimMontage* Animation);
    void InitAnimations();
    void OnEquipFinished(USkeletalMeshComponent *MeshComponent);
    void OnReloadFinished(USkeletalMeshComponent *MeshComponent);


    bool CanReload() const;

    void OnEmptyClip(ASTUBaseWeapon* AmmoEmptyWeapon);
    void ChangeClip();


};
