// DU INC

#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjectTile.h"

void ASTULauncherWeapon::StartFire()
{
    MakeShot();
}

void ASTULauncherWeapon::MakeShot()
{
    if (!GetWorld() || IsAmmoEmpty())
    {
        return;
    }

    FVector TraceStart;
    FVector TraceEnd;
    if (!GetTraceData(TraceStart, TraceEnd))
    {
        return;
    }

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd; 
    const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

    const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
    ASTUProjectTile* ProjectTile = GetWorld()->SpawnActorDeferred<ASTUProjectTile>( ProjectTileClass, SpawnTransform);
    if (ProjectTile)
    {
        ProjectTile->SetShotDirection(Direction);
        ProjectTile->SetOwner(GetOwner());
        ProjectTile->FinishSpawning(SpawnTransform);
    }

    DecreaseAmmo();
    SpawnMuzzleFX();
}
