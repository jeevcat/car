// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockState.h"

#include "BlockSpecification.h"
#include "BlocksComponent.h"

UBlockState*
UBlockState::Create(UBlockSpecification* Specification, UBlocksComponent* OwningComponent, const FIntVector& Location)
{
    UBlockState* BlockState = NewObject<UBlockState>(OwningComponent, Specification->StateClass);
    BlockState->OwningComponent = OwningComponent;
    BlockState->Specification = Specification;
    BlockState->Location = Location;
    BlockState->Init();
    return BlockState;
}

void UBlockState::Init()
{
}

const FIntVector& UBlockState::GetLocation() const
{
    return Location;
}
