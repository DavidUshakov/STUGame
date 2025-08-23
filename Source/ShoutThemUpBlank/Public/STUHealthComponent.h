// DU INC

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/DamageEvents.h"
#include "STUCoreTypes.h"

#include "STUHealthComponent.generated.h"

class UCameraShakeBase;
class UPhysicalMaterial;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOUTTHEMUPBLANK_API USTUHealthComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    // Sets default values for this component's properties
    USTUHealthComponent();

    bool TryToAddHealth(int32 HealthAmount);

    float GetHealth() const
    {
        return Health;
    }

    UFUNCTION(BlueprintCallable, category = "Health")
    float GetHealthPercent() const
    {
        return Health / MaxHealth;
    }

    UFUNCTION(BlueprintCallable)
    bool IsDead() const
    {
        return Health <= 0.0f;
    }

    bool IsHealthFull() const
    {
        return FMath::IsNearlyEqual(Health, MaxHealth);
    }

    FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
    bool AutoHeal = true;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (EditCondition = "AutoHeal"))
    float HealUpdateTime = 0.03f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (EditCondition = "AutoHeal"))
    float HealDelay = 3.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (EditCondition = "AutoHeal"))
    float HealModifier= 0.1f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
    TSubclassOf<UCameraShakeBase> CameraShake;

  protected:
    // Called when the game starts
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "1.0", ClampMax = "1000.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
    TMap<UPhysicalMaterial *, float> DamageModifiers;

  private:
    float Health = 0.0f;

    FTimerHandle HealTimer;

    UFUNCTION()
    void OnTakeAnyDamageHandle(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                                    AController *InstigatedBy, AActor *DamageCauser);

    UFUNCTION()
    void OnTakePointDamage(AActor *DamagedActor, float Damage, class AController *InstigatedBy, FVector HitLocation,
                           class UPrimitiveComponent *FHitComponent, FName BoneName, FVector ShotFromDirection,
                           const class UDamageType *DamageType, AActor *DamageCauser);

    UFUNCTION()
    void OnTakeRadialDamage(AActor * DamagedActor, float Damage,
                            const class UDamageType * DamageType, FVector Origin, const FHitResult & HitInfo,
                            class AController * InstigatedBy, AActor * DamageCauser);

    UFUNCTION()
    void OnHeal(/*float Heal*/);

    void SetHealth(float NewHealth);

    void PlayCameraShake();

    void Killed(AController *Killer);
    void ApplyDamage(float Damage, AController *InstigatedBy);
    float GetPointDamageModifier(AActor *DamagedActor, const FName &BoneName);
    void ReportDamageEvent(float Damage, const AController *InstigatedBy);
};
