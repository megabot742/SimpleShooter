// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAndFireGameMode.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AGunAndFireGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	//...
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false); //Lose
	}
	//For loop over ShooterAI in world
	for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!Controller->IsDead()) //check AI 
		{
			return;
		}
	}
	EndGame(true); // Win
}

void AGunAndFireGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner; //check true - false
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
			
	}
}
