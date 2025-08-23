// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjectTile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class USTUWeaponFXComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUProjectTile : public AActor
{
    GENERATED_BODY()

   public:
    // Sets default values for this actor's properties
    ASTUProjectTile();

    void SetShotDirection(const FVector& Direction)
    {
        ShotDirection = Direction;
    }

protected:
    UPROPERTY(VisibleAnywhere, Category = "Weapon")
    USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "Weapon")
    UProjectileMovementComponent *MovementComponent;

    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    float DamageRadius = 200.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
    float DamageAmount = 20.0f;

    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    bool DoFullDamage;

    UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
    float LifeSeconds = 5.0f;

    UPROPERTY(VisibleAnywhere, Category = "VFX")
    USTUWeaponFXComponent *WeaponFXComponent;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    FVector ShotDirection;

    UFUNCTION()
    void OnProjectileHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp,
                         FVector NormalImpulse, const FHitResult &Hit);

    AController *GetController() const;
};
