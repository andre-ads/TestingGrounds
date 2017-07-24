// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingComponent.h"
#include "../Public/PatrollingComponent.h"

UPatrollingComponent::UPatrollingComponent() { PrimaryComponentTick.bCanEverTick = false; }
AActor * UPatrollingComponent::GetWaypointActor(int32 Index) const { return PatrolWaypoints[Index]; }
int32 UPatrollingComponent::GetWaypointArrayLength() const { return PatrolWaypoints.Num(); }