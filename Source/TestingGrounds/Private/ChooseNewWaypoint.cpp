// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNewWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "PatrollingComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNewWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto NextIndex = BlackboardComponent->GetValueAsInt(Index.SelectedKeyName);
	auto PatrollingComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrollingComponent>();

	if (!ensure(PatrollingComponent)) { return EBTNodeResult::Failed; }

	BlackboardComponent->SetValueAsObject(Waypoint.SelectedKeyName, PatrollingComponent->GetWaypointActor(NextIndex));
	BlackboardComponent->SetValueAsInt(Index.SelectedKeyName, (NextIndex + 1) % PatrollingComponent->GetWaypointArrayLength());

	return EBTNodeResult::Succeeded;
}