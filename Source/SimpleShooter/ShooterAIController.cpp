// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet//GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	//....	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		
	}
}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//....
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//bool CheckPlayer = LineOfSightTo(PlayerPawn);
	//if (CheckPlayer)
	//{
	//	//SetFocus(PlayerPawn);
	//	//MoveToActor(PlayerPawn, AcceptanceRadius);
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
	//}
	//else
	//{
	//	//ClearFocus(EAIFocusPriority::Gameplay);
	//	//StopMovement();
	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControllerCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControllerCharacter != nullptr)
	{
		return ControllerCharacter->IsDead();
	}
	return true;
}
