#include "BlockDirection.h"

namespace
{
const TMap<EBlockDirection, FIntVector> Directions{
    {{EBlockDirection::Front}, {1, 0, 0}},
    {{EBlockDirection::Behind}, {-1, 0, 0}},
    {{EBlockDirection::Right}, {0, 1, 0}},
    {{EBlockDirection::Left}, {0, -1, 0}},
    {{EBlockDirection::Above}, {0, 0, 1}},
    {{EBlockDirection::Below}, {0, 0, -1}},
};
}

FIntVector BlockDirection::ToOffset(const EBlockDirection Direction)
{
    return Directions[Direction];
}
