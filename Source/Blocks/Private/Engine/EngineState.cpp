// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineState.h"

float UEngineState::GetPower() const
{
    TArray<UEngineState*> Neighbors = GetNeighboringStates<UEngineState>();
    return 0;
}
