// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineState.h"

#include "EngineSpecification.h"

UEngineSpecification* UEngineState::GetSpecification() const
{
    return static_cast<UEngineSpecification*>(Super::GetSpecification());
}

float UEngineState::GetTotalPower() const
{
    float TotalPower = 0.f;
    VisitConnectedStates<UEngineState>([&](const UEngineState* State)
                                       { TotalPower += State->GetSpecification()->Power; });
    return TotalPower;
}
