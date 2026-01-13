// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AudioOptionsView.generated.h"

class USlider;
class UTextBlock;
class UMyOptionsWidget;

/**
 * 
 */
UCLASS()
class UAudioOptionsView : public UUserWidget
{
	GENERATED_BODY()
		
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	UMyOptionsWidget* m_ParentWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* HeaderTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* MainSoundLevelTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* BgSoundLevelTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* MuteMainSoundTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	UTextBlock* MuteBgSoundTextBlock;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	USlider* MainSoundLevelSlider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	USlider* BgSoundLevelSlider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	USlider* MuteMainSoundSlider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	USlider* MuteBgSoundSlider;
	
	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnToggleMainMute();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnToggleBgMute();

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnMainSoundLevelChanged(float value);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void OnBgSoundLevelChanged(float value);
};
