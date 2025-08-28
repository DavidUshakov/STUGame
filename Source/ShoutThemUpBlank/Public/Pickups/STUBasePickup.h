// DU INC

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUBasePickup.generated.h"

class USphereComponent;
class USoundCue;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUBasePickup : public AActor
{
    GENERATED_BODY()

  public:
    // Sets default values for this actor's properties
    ASTUBasePickup();

    bool CouldBeTaken() const;

protected:
    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    USphereComponent *CollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "Pickup")
    float RespawnTime = 5.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue *PickupSound;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    virtual void NotifyActorBeginOverlap(AActor *OtherActor) override;

  public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    float RotationYaw = 0.0f;
    FTimerHandle RespawnTimerHandle;

    virtual bool GivePickupTo(APawn *PlayerPawn);
    void PickupWasTaken();
    void Respawn();
    void GenerateRotationYaw();
};
