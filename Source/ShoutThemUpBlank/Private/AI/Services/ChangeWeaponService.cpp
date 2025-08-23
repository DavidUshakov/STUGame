// DU INC

#include "AI/Services/ChangeWeaponService.h"
#include "AIController.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"

UChangeWeaponService::UChangeWeaponService()
{
    NodeName = "Change Weapon";
}

void UChangeWeaponService::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, const float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    if (FMath::FRand() > Probability)
    {
        return;
    }

    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller)
    {
        return;
    }

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    if (!WeaponComponent)
    {
        return;
    }

    WeaponComponent->NextWeapon();
}
