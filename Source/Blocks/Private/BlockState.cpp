// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockState.h"

#include "BlockSpecification.h"
#include "BlocksComponent.h"

UBlockState* UBlockState::Create(
    UBlockSpecification* Specification,
    UBlocksComponent* OwningComponent,
    const FIntVector& Location)
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

UBlockSpecification* UBlockState::GetSpecification() const
{
    return Specification;
}

const FIntVector& UBlockState::GetLocation() const
{
    return Location;
}

UBlockState* UBlockState::GetNeighborState(const EBlockDirection Direction) const
{
    return OwningComponent->GetState(GetLocation() + BlockDirection::ToOffset(Direction));
}

TArray<UBlockState*> UBlockState::GetAdjacentConnectedStates(const TSubclassOf<UBlockState> Class) const
{
    TArray<UBlockState*> Neighbors;
    for (const EBlockDirection Dir : TEnumRange<EBlockDirection>())
    {
        if (!EnumHasAnyFlags(static_cast<EBlockDirection>(Specification->ValidConnectionDirections), Dir))
        {
            continue;
        }
        UBlockState* Neighbor = GetNeighborState(Dir);
        if (!Neighbor || Neighbor->GetClass() != Class)
        {
            continue;
        }
        Neighbors.Add(Neighbor);
    }
    return Neighbors;
}

void UBlockState::VisitConnectedStates(
    const TSubclassOf<UBlockState> Class,
    const TFunction<void(const UBlockState*)> Visitor) const
{
    const UBlockState* Self = this;
    TQueue<const UBlockState*> Queue;
    Queue.Enqueue(Self);
    TSet<const UBlockState*> Visited;
    Visited.Add(Self);
    while (!Queue.IsEmpty())
    {
        const UBlockState* State;
        Queue.Dequeue(State);
        Visitor(State);

        for (const UBlockState* Neighbor : State->GetAdjacentConnectedStates(Class))
        {
            if (Visited.Contains(Neighbor))
            {
                continue;
            }
            Visited.Add(Neighbor);
            Queue.Enqueue(Neighbor);
        }
    }
}
