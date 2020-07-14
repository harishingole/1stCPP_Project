// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEMOCPP_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual bool  Initialize();

private:

	bool bShow = true;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MessageTextBlock;

	UPROPERTY(meta = (BindWidget))
		class UCanvasPanel* MenuCanvasPanel;

	UPROPERTY(meta = (BindWidget))
		class UButton* ToggleButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* VisibleTheText;

	UFUNCTION()
		void OnToggleButtonClicked();
};
