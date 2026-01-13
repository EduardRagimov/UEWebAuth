// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyQuitGameWidget.generated.h"

class UButton;
class UInGameMenuWidget;

/**
 * Quit Game Dialog
 */
UCLASS()
class UMyQuitGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	UInGameMenuWidget* m_ParentWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* ConfirmButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* RejectButton;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnAccept();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnReject();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnShow(UInGameMenuWidget* parent_);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnHide();

private:
	/* hold input */
	bool canInteract;
};
