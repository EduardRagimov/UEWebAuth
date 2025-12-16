// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInGameMenuWidget;

/**
 * Player Controller
 */
UCLASS()
class WEBAUTHUE5_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (DisplayThumbnail))
	TSubclassOf<UInGameMenuWidget> wMainMenu;

	UPROPERTY()
	UInGameMenuWidget* m_MainMenu;

private:
	/* setup */
	void SetupView();

	/* show main menu */
	void ShowMainMenu();

	/* escape button perssed */
	void OnEsc();
};
