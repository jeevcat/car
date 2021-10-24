#include "BlockDirection.h"

namespace
{
const TMap<EBlockDirection, FIntVector> Directions{
    {EBlockDirection::Front, {1, 0, 0}},
    {EBlockDirection::Behind, {-1, 0, 0}},
    {EBlockDirection::Right, {0, 1, 0}},
    {EBlockDirection::Left, {0, -1, 0}},
    {EBlockDirection::Above, {0, 0, 1}},
    {EBlockDirection::Below, {0, 0, -1}},
};

const TMap<EBlockDirection, EAxisList::Type> Axes{
    {EBlockDirection::Front, EAxisList::Y},
    {EBlockDirection::Behind, EAxisList::Y},
    {EBlockDirection::Right, EAxisList::X},
    {EBlockDirection::Left, EAxisList::X},
    {EBlockDirection::Above, EAxisList::Z},
    {EBlockDirection::Below, EAxisList::Z},
};
}    // namespace

FIntVector BlockDirection::ToOffset(const EBlockDirection Direction)
{
    return Directions[Direction];
}

EAxisList::Type BlockDirection::ToAxis(EBlockDirection Direction)
{
    return Axes[Direction];
}
