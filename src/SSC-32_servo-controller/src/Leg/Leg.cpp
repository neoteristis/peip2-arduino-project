#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "Leg.h"

Leg::Leg()
{
    // HOLDER
}

Leg::Leg(int legNumber)
{
    // Constants for LEG A
    int OFFSET_GENOU_A = 170;
    int OFFSET_HANCHE_A = 170;
    int OFFSET_EPAULE_A = 42;

    // Constants for LEG B
    int OFFSET_GENOU_B = 0;
    int OFFSET_HANCHE_B = 0;
    int OFFSET_EPAULE_B = 74;

    // Constants for LEG C
    int OFFSET_GENOU_C = 0;
    int OFFSET_HANCHE_C = 0;
    int OFFSET_EPAULE_C = 154;

    // Constants for LEG D
    int OFFSET_GENOU_D = 170;
    int OFFSET_HANCHE_D = 170;
    int OFFSET_EPAULE_D = 91;
}