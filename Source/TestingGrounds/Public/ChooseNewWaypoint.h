// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNewWaypoint.generated.h"

UCLASS()
class TESTINGGROUNDS_API UChooseNewWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector Index;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector Waypoint;
};
