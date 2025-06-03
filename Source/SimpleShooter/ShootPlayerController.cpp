// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootPlayerController.h"
#include "Blueprint/UserWidget.h"

void AShootPlayerController::BeginPlay()
{
    Super::BeginPlay();
    Hub = CreateWidget<UUserWidget>(this, HubClass);
    if (Hub != nullptr)
    {
        Hub->AddToViewport();
    }
}

void AShootPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

    Hub->RemoveFromViewport();
    if (bIsWinner)
    {
        UUserWidget* WinScreen = CreateWidget<UUserWidget>(this, WinScreenClass);
        if (WinScreen != nullptr)
        {
            WinScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget<UUserWidget>(this, LoseScreenClass);
        if (LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }


	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDeplay);
}
