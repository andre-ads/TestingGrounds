// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrollingComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UPatrollingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPatrollingComponent();

	AActor* GetWaypointActor(int32 Index) const;
	int32 GetWaypointArrayLength() const;

protected:
	UPROPERTY(EditInstanceOnly, Category = "Waypoints")
		TArray<AActor*> PatrolWaypoints;
};
