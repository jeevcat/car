#pragma once
#include "BlockDirection.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "BlockSpecification.generated.h"

class UBlockState;

UCLASS()
class BLOCKS_API UBlockSpecification : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere)
    FText HumanName;

    // Can be null if no state needed
    UPROPERTY(EditAnywhere)
    TSubclassOf<UBlockState> StateClass;

    // Can be null if no component needed
    UPROPERTY(EditAnywhere)
    TSubclassOf<USceneComponent> ComponentClass;

    UPROPERTY(EditAnywhere, meta = (Bitmask, BitmaskEnum = EBlockDirection))
    int32 ValidConnectionDirections = static_cast<int32>(EBlockDirection::XYZ);
};
