// DU INC

#pragma once

#include "CoreMinimal.h"
#include "STUBaseCharacter.h"

#include "STUPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USphereComponent;

UCLASS()
class SHOUTTHEMUPBLANK_API ASTUPlayerCharacter : public ASTUBaseCharacter
{
    GENERATED_BODY()

public:
    explicit ASTUPlayerCharacter(const FObjectInitializer &ObjInit);

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

  protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent *SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent *CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USphereComponent *CameraCollisionComponent;

    virtual void OnDeath() override;

    virtual void BeginPlay() override;

  private:
    // Performs move of the character forward or backward.
    // Amount - the value of how far shoud be moved the character.  Must be in range of -1.0 to 1.0
    void MoveForward(float Amount);

    // Performs move of the character right or left.
    // Amount - the value of how far shoud be moved the character.  Must be in range of -1.0 to 1.0
    void MoveRight(float Amount);

    // Rotates of the character camera up or down.
    // Amount - the value of how far shoud be rotated the camera.  Must be in range of -1.0 to 1.0
    void LookUp(float Amount);

    // Rotates of the character camera right or left.
    // Amount - the value of how far shoud be moved the camera.  Must be in range of -1.0 to 1.0
    void TurnAround(float Amount);

    // Performs fast move of the character in the direction passed to MoveForware and MoveRight.
    // Amount - the value of how far shoud be moved the character.  Must be in range of -1.0 to 1.0
    void Run(volatile float Amount);

    UFUNCTION()
    void OnCameraCollisionBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor,
                            UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

    UFUNCTION()
    void OnCameraCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    void CheckCameraOverlap();
};
