// Fill out your copyright notice in the Description page of Project Settings.

#include "EngineState.h"

float UEngineState::GetPower() const
{
    TArray<UEngineState*> Neighbors = GetNeighboringStates<UEngineState>(EAxisList::X);
    return 0;
}

TSharedRef<FEngineShaft> UEngineState::GetShaft()
{
    if (OwnedShaft)
    {
        return OwnedShaft.ToSharedRef();
    }
    for (const UEngineState* State : GetNeighboringStates<UEngineState>(EAxisList::X))
    {
        if (State->OwnedShaft)
        {
            return State->OwnedShaft.ToSharedRef();
        }
    }

    OwnedShaft = MakeShared<FEngineShaft>();
    return OwnedShaft.ToSharedRef();
}
