// DU INC

#include "AI/Decorators/STUNeedAmmo.h"
#include "STUBaseWeapon.h"
#include "STUUtils.h"
#include "Components/STUWeaponComponent.h"
#include "AIController.h"

USTUNeedAmmo::USTUNeedAmmo()
{
    NodeName = "Need Ammo";
}

bool USTUNeedAmmo::CalculateRawConditionValue(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) const
{
    if (!WeaponType)
    {
        return false;
    }

    const auto Controller = OwnerComp.GetAIOwner();
    if (!Controller)
    {
        return false;
    }

    const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
    return WeaponComponent && WeaponComponent->NeedAmmo(WeaponType);
}
