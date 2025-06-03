// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SeenPlayer.h"
#include "Kismet//GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


UBTService_SeenPlayer::UBTService_SeenPlayer()
{
	NodeName = "Seen Player Yet";
}

void UBTService_SeenPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	//...
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn == nullptr)
	{
		return;
	}
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}
	if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
	{
		//OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
	}
}

