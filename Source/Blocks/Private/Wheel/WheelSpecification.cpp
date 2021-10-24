#include "Wheel/WheelSpecification.h"

UWheelSpecification::UWheelSpecification()
{
    Wheel = CreateDefaultSubobject<UChaosVehicleWheel>(TEXT("Wheel"));
}
