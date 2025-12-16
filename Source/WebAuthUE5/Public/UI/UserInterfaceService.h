#pragma once
#include <stack>

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserInterfaceService.generated.h"

UCLASS()
class UserInterfaceService : public UObject
{
	GENERATED_BODY()

private:
	static UserInterfaceService* Instance;
	
#pragma region Views
	std::stack<UUserWidget*> WidgetStack;
	
	/**
	 * In-Game UI
	 */
	
	UPROPERTY()
	UUserWidget* InGameView;
	
	/**
	 * Main Menu
	 */	
	UPROPERTY()
	UUserWidget* MainMenuView;
		
	/**
	 * Pause Menu
	 */
	UPROPERTY()
	UUserWidget* PauseMenuView;
		
	/**
	 * Loading Screen 
	 */
	UPROPERTY()
	UUserWidget* LoadingScreenView;
	
#pragma endregion
	
	
	UserInterfaceService(){ }
	void Initialize();
	void SetViews();
	
public:
	static bool HasInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (DisplayThumbnail))
	TSubclassOf<UUserWidget> wIngameMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (DisplayThumbnail))
	TSubclassOf<UUserWidget> wMainMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (DisplayThumbnail))
	TSubclassOf<UUserWidget> wPauseMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets", meta = (DisplayThumbnail))
	TSubclassOf<UUserWidget> wLoadingScreen;
	
	static UserInterfaceService* GetInstance()
	{
		if (!HasInstance)
		{
			// Create the instance if it doesn't exist
			Instance = NewObject<UserInterfaceService>();
			Instance->Initialize();
			
			// Prevent it from being garbage collected
			Instance->AddToRoot();
		}

		return Instance;
	}
	
	// Example service function
	UFUNCTION(BlueprintCallable, Category = "Singleton Service")
	void PerformServiceOperation(const FString& Data)
	{
		UE_LOG(LogTemp, Warning, TEXT("UserInterfaceService: Singleton performing operation with data: %s"), *Data);
	}
};
