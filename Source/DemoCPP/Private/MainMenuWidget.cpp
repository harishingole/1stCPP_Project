// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

bool UMainMenuWidget::Initialize()
{
	UE_LOG(LogTemp, Warning, TEXT("In Initialize Block"));

	Super::Initialize();

	if (MessageTextBlock == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No textblock class found"));
		return false;
	}

	MessageTextBlock->SetText(FText::FromString("Welcome to The World Of Computer Science"));

	if (ToggleButton && VisibleTheText == nullptr) return false;

	
	ToggleButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnToggleButtonClicked);
	VisibleTheText->SetVisibility(ESlateVisibility::Hidden);
	VisibleTheText->OnClicked.AddDynamic(this, &UMainMenuWidget::OnToggleButtonClicked);


	return true;
}

void UMainMenuWidget::OnToggleButtonClicked()
{
	if (MessageTextBlock == nullptr) return;
	
	if (bShow)
	{
		
		MessageTextBlock->SetVisibility(ESlateVisibility::Hidden);
		bShow = false;
		ToggleButton->SetVisibility(ESlateVisibility::Hidden);
		VisibleTheText->SetVisibility(ESlateVisibility::Visible);
	}
	
	else
	{
		
		MessageTextBlock->SetVisibility(ESlateVisibility::Visible);
		bShow = true;
		ToggleButton->SetVisibility(ESlateVisibility::Visible);
		VisibleTheText->SetVisibility(ESlateVisibility::Hidden);
	}
}

