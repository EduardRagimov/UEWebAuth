// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyOptionsWidget.generated.h"

class UButton;
class UTextBlock;
class UGameplayOptionsView;
class UAudioOptionsView;
class UControlOptionsView;
class UVideoOptionsView;

/**
 * Options View
 */
UCLASS()
class UMyOptionsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* HeaderTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	UUserWidget* m_ParentWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sub Views")
	UGameplayOptionsView* GameplayOptionsWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sub Views")
	UAudioOptionsView* AudioOptionsWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sub Views")
	UControlOptionsView* ControlOptionsWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sub Views")
	UVideoOptionsView* VideoOptionsWidget;
        
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* ApplyButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UButton* RejectButton;

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnApply();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnReject();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnShow(UInGameMenuWidget* parent);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnHide();

private:
	/* hold input */
	bool canInteract;
};
