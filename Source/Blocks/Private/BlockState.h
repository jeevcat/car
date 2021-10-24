// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockDirection.h"
#include "BlocksComponent.h"
#include "CoreMinimal.h"
#include "Math/Axis.h"
#include "UObject/NoExportTypes.h"

#include "BlockState.generated.h"

class UBlocksComponent;
class UBlockSpecification;
/**
 *
 */
UCLASS(Abstract)
class UBlockState : public UObject
{
    GENERATED_BODY()

public:
    static UBlockState* Create(UBlockSpecification*, UBlocksComponent* OwningComponent, const FIntVector& Location);
    virtual void Init();

    const FIntVector& GetLocation() const;

    template <class T>
    TArray<T*> GetConnectedStates() const;

    template <class T>
    TArray<T*> GetNeighboringStates(EAxisList::Type Axes = EAxisList::All) const;
    template <class T>
    T* GetNeighborState(EBlockDirection) const;

protected:
    UPROPERTY()
    UBlocksComponent* OwningComponent;

private:
    UPROPERTY()
    UBlockSpecification* Specification;

    FIntVector Location;
};

template <class T>
TArray<T*> UBlockState::GetConnectedStates() const
{
    TArray<T*> Neighbors;
    for (const EBlockDirection Dir : TEnumRange<EBlockDirection>())
    {
        if (!EnumHasAnyFlags(static_cast<EBlockDirection>(Specification->ValidConnectionDirections), Dir))
        {
            continue;
        }
        if (T* State = GetNeighborState<T>(Dir))
        {
            Neighbors.Add(State);
        }
    }
    return Neighbors;
}

template <class T>
TArray<T*> UBlockState::GetNeighboringStates(const EAxisList::Type Axes) const
{
    TArray<T*> Neighbors;
    return Neighbors;
}

template <class T>
T* UBlockState::GetNeighborState(const EBlockDirection Direction) const
{
    return OwningComponent->GetState<T>(GetLocation() + BlockDirection::ToOffset(Direction));
}
