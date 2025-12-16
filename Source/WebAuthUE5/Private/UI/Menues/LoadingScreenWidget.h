#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoadingScreenWidget.generated.h"


UCLASS(Abstract)
class ULoadingScreenWidget : public UUserWidget
{
	GENERATED_BODY()


	virtual bool Initialize() override;

public:
	/**
	 * Show the menu main menu content
	 * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void Show();

	/** 
	 * Hide the menu
	 * */
	UFUNCTION(BlueprintCallable, Category = "Function")
	virtual void Hide();
};
