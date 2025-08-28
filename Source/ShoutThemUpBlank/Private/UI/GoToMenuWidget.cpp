// DU INC

#include "UI/GoToMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogGoToMenuWidget, All, All);

void UGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (MenuButton)
    {
        MenuButton->OnClicked.AddDynamic(this, &UGoToMenuWidget::OnMenu);
    }
}

void UGoToMenuWidget::OnMenu()
{
    if (!GetWorld())
    {
        return;
    }

    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance)
    {
        return;
    }

    if (STUGameInstance->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogGoToMenuWidget, Error, TEXT("Menu Level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}
