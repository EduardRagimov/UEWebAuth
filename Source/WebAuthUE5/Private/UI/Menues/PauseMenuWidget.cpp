#include "PauseMenuWidget.h"

bool UPauseMenuWidget::Initialize()
{
	return Super::Initialize();
}

void UPauseMenuWidget::SetOwner(ULocalPlayer* playerOwner)
{
	PlayerOwner = playerOwner;
}

void UPauseMenuWidget::Show()
{
	if (IsVisible()) return;
	SetVisibility(ESlateVisibility::Visible);
}

void UPauseMenuWidget::Hide()
{
	if (!IsVisible()) return;
	SetVisibility(ESlateVisibility::Hidden);
}
