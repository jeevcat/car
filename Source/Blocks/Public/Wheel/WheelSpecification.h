#pragma once

#include "BlockSpecification.h"
#include "ChaosVehicleWheel.h"
#include "CoreMinimal.h"

#include "WheelSpecification.generated.h"

UCLASS()
class BLOCKS_API UWheelSpecification final : public UBlockSpecification
{
    GENERATED_BODY()

public:
    UWheelSpecification();
    UPROPERTY(EditAnywhere, Instanced, NoClear, meta = (ShowOnlyInnerProperties))
    TObjectPtr<UChaosVehicleWheel> Wheel;
};
