#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EBlockDirection : uint8
{
    Front,
    Behind,
    Right,
    Left,
    Above,
    Below,
    Num UMETA(Hidden)
};

ENUM_RANGE_BY_COUNT(EBlockDirection, EBlockDirection::Num);

namespace BlockDirection
{
FIntVector ToOffset(EBlockDirection Direction);
}
