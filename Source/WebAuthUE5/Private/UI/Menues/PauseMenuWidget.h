#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"


UCLASS(Abstract)
class UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;

public:
	/**
	 * Sets owning player controller
	 */
	UFUNCTION(BlueprintCallable, Category = "Function")
	void SetOwner(ULocalPlayer* playerOwner);


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

private:
	/** 
	 * Owning player controller
	 */
	ULocalPlayer* PlayerOwner;
};
