// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNewWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNewWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto NextIndex = BlackboardComponent->GetValueAsInt(Index.SelectedKeyName);
	auto ControlledPawn = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());

	BlackboardComponent->SetValueAsObject(Waypoint.SelectedKeyName, ControlledPawn->PatrolWaypoints[NextIndex]);
	BlackboardComponent->SetValueAsInt(Index.SelectedKeyName, (NextIndex + 1) % ControlledPawn->PatrolWaypoints.Num());

	return EBTNodeResult::Succeeded;
}