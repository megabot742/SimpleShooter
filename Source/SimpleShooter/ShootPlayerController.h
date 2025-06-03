// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShootPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShootPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:
	UPROPERTY(EditAnywhere) TSubclassOf<class UUserWidget> LoseScreenClass;
	UPROPERTY(EditAnywhere) TSubclassOf<class UUserWidget> WinScreenClass;
	UPROPERTY(EditAnywhere) TSubclassOf<class UUserWidget> HubClass;
	UPROPERTY(EditAnywhere) float RestartDeplay = 5.f; //reset after 5 second

	FTimerHandle RestartTimer;
	UPROPERTY(VisibleAnywhere) UUserWidget* Hub;
};
