#include "LoadingScreenWidget.h"

bool ULoadingScreenWidget::Initialize()
{
	return Super::Initialize();
}

void ULoadingScreenWidget::Show()
{
	if (IsVisible()) return;
	SetVisibility(ESlateVisibility::Visible);
}

void ULoadingScreenWidget::Hide()
{
	if (!IsVisible()) return;
	SetVisibility(ESlateVisibility::Hidden);
}
