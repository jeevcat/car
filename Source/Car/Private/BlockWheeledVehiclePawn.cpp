// Fill out your copyright notice in the Description page of Project Settings.

#include "BlockWheeledVehiclePawn.h"

#include "Wheel/WheelSpecification.h"

ABlockWheeledVehiclePawn::ABlockWheeledVehiclePawn()
{
    Blocks = CreateDefaultSubobject<UBlocksComponent>(TEXT("Blocks"));
}

void ABlockWheeledVehiclePawn::PostInitializeComponents()
{
    Super::PostInitializeComponents();
}

void ABlockWheeledVehiclePawn::PostRegisterAllComponents()
{
    Super::PostRegisterAllComponents();
}

void ABlockWheeledVehiclePawn::InitWheels()
{
    if (Blocks->GetBlockInstances().Num() == 0)
    {
        return;
    }

    struct FLocatedWheel
    {
        FIntVector Location;
        UWheelSpecification* Spec;
    };

    // Sort front to back
    TArray<FLocatedWheel> Sorted;
    for (const auto& [Coords, BlockInstance] : Blocks->GetBlockInstances())
    {
        if (UWheelSpecification* Spec = Cast<UWheelSpecification>(BlockInstance.Type))
        {
            Sorted.Add(FLocatedWheel{Coords, Spec});
        }
    }
    Sorted.Sort([](const FLocatedWheel& A, const FLocatedWheel& B) { return A.Location.X < B.Location.X; });

    // Sort left to right and choose leftmost and rightmost
    TArray<FLocatedWheel> RowWheels;
    int32 X = Sorted[0].Location.X;
    for (const FLocatedWheel& Wheel : Sorted)
    {
        if (Wheel.Location.X == X)
        {
            RowWheels.Add(Wheel);
        }
        else
        {
            RowWheels.Sort([](const FLocatedWheel& A, const FLocatedWheel& B) { return A.Location.Y < B.Location.Y; });
            UWheelSpecification* Leftmost = RowWheels[0].Spec;
            UWheelSpecification* Rightmost = RowWheels.Last().Spec;

            // Reset
            RowWheels.Empty();
            X = Wheel.Location.X;
        }
    }
}

#if WITH_EDITOR
void ABlockWheeledVehiclePawn::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif
