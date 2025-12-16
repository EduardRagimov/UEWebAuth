#include "MainMenuWidget.h"

bool UMainMenuWidget::Initialize()
{
	return Super::Initialize();
}

void UMainMenuWidget::SetOwner(ULocalPlayer* playerOwner)
{
	PlayerOwner = playerOwner;
}

void UMainMenuWidget::Show()
{
	if (IsVisible()) return;
	SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuWidget::Hide()
{
	if (!IsVisible()) return;
	SetVisibility(ESlateVisibility::Hidden);
}
