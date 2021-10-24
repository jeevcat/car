// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BlockDirection.h"
#include "BlocksComponent.h"
#include "CoreMinimal.h"
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

    virtual UBlockSpecification* GetSpecification() const;
    const FIntVector& GetLocation() const;

    UBlockState* GetNeighborState(EBlockDirection) const;

    TArray<UBlockState*> GetAdjacentConnectedStates(TSubclassOf<UBlockState>) const;

    void VisitConnectedStates(TSubclassOf<UBlockState>, TFunction<void(const UBlockState*)> Visitor) const;
    template <class T>
    void VisitConnectedStates(TFunction<void(const T*)> Visitor) const
    {
        VisitConnectedStates(
            T::StaticClass(), [&Visitor](const UBlockState* State) { Visitor(static_cast<const T*>(State)); });
    }

protected:
    UPROPERTY(Transient)
    UBlocksComponent* OwningComponent;

    UPROPERTY(Transient)
    UBlockSpecification* Specification;

private:
    FIntVector Location;
};
