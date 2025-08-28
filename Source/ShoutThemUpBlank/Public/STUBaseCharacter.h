// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"


class USTUHealthComponent;
class USTUWeaponComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUBaseCharacter : public ACharacter
{
    GENERATED_BODY()

  public:
    // Sets default values for this character's properties
    explicit ASTUBaseCharacter(const FObjectInitializer &ObjInit);


  protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTUHealthComponent* HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTUWeaponComponent* WeaponComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage* DeathAnimMontage;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

    UPROPERTY(EditDefaultsOnly, Category = "Material")
    FName MaterialColorName = "Paint Color";

    // Performs logic related to changing character health.
    // Health - the new value for character health.
    virtual void OnHealthChanged(float Health, float HealthDelta);

  public:
    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    virtual void TurnOff() override;
    virtual void Reset() override;

    // Performs logic related to character death.
    virtual void OnDeath();

    void SetPlayerColor(const FLinearColor &Color);

private:

    // Performs logic related to landing of the character.
    // Hit - contains information about the contact of two objects.
    UFUNCTION()
    void OnGroundLanded(const FHitResult &Hit);
};
