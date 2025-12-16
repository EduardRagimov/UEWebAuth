#include "UI/UserInterfaceService.h"
#include "UI/Menues/MainMenuWidget.h"
#include "UI/Menues/PauseMenuWidget.h"
#include "Menues/InGameMenuWidget.h"
#include "Menues/LoadingScreenWidget.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Initialize the static pointer
UserInterfaceService* UserInterfaceService::Instance = nullptr;
#pragma region InGameMenu
void HideInGameMenu()
{
}

void ShowInGameMenu()
{
}
#pragma endregion

#pragma region MainMenu
void HideMainMenu()
{
}

void ShowMainMenu()
{
}
#pragma endregion

#pragma region LoadingScreen
void HideLoadingScreen()
{
}

void ShowLoadingScreen()
{
}
#pragma endregion

#pragma region PauseMenu
void HidePauseMenu()
{
}

void ShowPauseMenu()
{
}
#pragma endregion

#pragma region SceneEventHandling

void Subscribe()
{
	// todo: refactoring: use GameSessionManager
	// SceneManager.sceneLoaded   += OnSceneLoadedHandler;
	// SceneManager.sceneUnloaded += OnSceneUnloadedHandler;
}

void Unsubscribe()
{
	// todo: refactoring: use GameSessionManager
	// SceneManager.sceneLoaded   -= OnSceneLoadedHandler;
	// SceneManager.sceneUnloaded -= OnSceneUnloadedHandler;
}

#pragma endregion

void UserInterfaceService::Initialize()
{
#pragma region MainMenu

	if (!MainMenuView)
	{
		MainMenuView = CreateWidget<UMainMenuWidget>(GetWorld(), wMainMenu);
	}

	MainMenuView->Initialize();
	HideMainMenu();

#pragma endregion

#pragma region In Game Menu

	if (!InGameView)
	{
		InGameView = CreateWidget<UInGameMenuWidget>(GetWorld(), wIngameMenu);
	}

	InGameView->Initialize();
	HideInGameMenu();

#pragma endregion

#pragma region Loading Screen

	if (!LoadingScreenView)
	{
		LoadingScreenView = CreateWidget<ULoadingScreenWidget>(GetWorld(), wLoadingScreen);
	}

	LoadingScreenView->Initialize();
	HideLoadingScreen();

#pragma endregion

#pragma region MessageBox
// todo:
	// if (!_messageBoxInstance)
	// {
	// 	_messageBoxInstance = CreateWidget<MessageBox.MessageBox>(this);
	// }
	//
	// if (!_messageBoxInstance)
	// {
	// 	_messageBoxInstance = AbstractView.GetView<MessageBox.MessageBox>(transform)
	// 	as
	// 	MessageBox.MessageBox;
	// }
	//
	// _messageBoxInstance->Initialize();
	// HideMessageBox();

#pragma endregion
	
//
// #pragma region OptionsView
//
// 	if (!_optionsView)
// 	{
// 		_optionsView = CreateWidget<OptionsView>(this);
// 	}
//
// 	if (!_optionsView)
// 	{
// 		_optionsView = AbstractView.GetView<OptionsView>(transform)
// 		as OptionsView;
// 	}
//
// 	_optionsView->Initialize();
// 	HideOptionsView();
//
// #pragma endregion

#pragma region PauseMenuView

	if (!PauseMenuView)
	{
		PauseMenuView = CreateWidget<UPauseMenuWidget>(GetWorld(), wPauseMenu);
	}

	PauseMenuView->Initialize();
	HidePauseMenu();

#pragma endregion

	// if (networkManagerView)
	// {
	// 	HideMultiplayerView();
	// }

	SetViews();

	Subscribe();
}

void UserInterfaceService::SetViews()
{
	// 1. Get a pointer to the current UWorld object
	UWorld* cWorld = GetWorld();
	if (!cWorld) return;

	// 2. Get the raw map name as an FString
	FString RawMapName = cWorld->GetMapName();

	// 3. Optional: Remove the editor prefix (e.g., UEDPIE_0_) for a clean name
	FString CleanMapName = UGameplayStatics::GetCurrentLevelName(cWorld, true);

	// Or, manually remove the prefix (more involved):
	// FString Prefix = MyWorld->StreamingLevelsPrefix;
	// FString FinalMapName = RawMapName.RemoveFromStart(Prefix);

	UE_LOG(LogTemp, Log, TEXT("Current Level Name: %s"), *CleanMapName);

	// todo: implement in game shop 
	// if (SceneManager.GetActiveScene().buildIndex == 0) // Init
	// ||  SceneManager.GetActiveScene().buildIndex == 1) // MainMenu
	if (CleanMapName == "MainMenu")
	{
		HideInGameMenu();
		ShowMainMenu();
	}
	else
	{
		HideMainMenu();
		ShowInGameMenu();
	}
}

/** Usage:
 * UserInterfaceService::GetInstance()->PerformServiceOperation(TEXT("Initialise Game Data"));
 * */

