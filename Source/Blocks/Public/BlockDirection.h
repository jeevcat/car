#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EBlockDirection : uint8
{
    None = 0 UMETA(Hidden),
    Front = 1 << 0,
    Behind = 1 << 1,
    Right = 1 << 2,
    Left = 1 << 3,
    Above = 1 << 4,
    Below = 1 << 5,

    X = Left | Right,
    Y = Front | Behind,
    Z = Above | Below,

    XY = X | Y,
    XZ = X | Z,
    YZ = Y | Z,
    XYZ = X | Y | Z,
};

ENUM_RANGE_BY_VALUES(
    EBlockDirection,
    EBlockDirection::Front,
    EBlockDirection::Behind,
    EBlockDirection::Right,
    EBlockDirection::Left,
    EBlockDirection::Above,
    EBlockDirection::Below);
ENUM_CLASS_FLAGS(EBlockDirection);

namespace BlockDirection
{
FIntVector ToOffset(EBlockDirection Direction);
}    // namespace BlockDirection
