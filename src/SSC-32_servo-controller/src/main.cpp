#include <Arduino.h>
#include "PolyDog/PolyDog.h"
#include "CustomServos/CustomServos.h"
#include "Leg/Leg.h"

PolyDog dog = PolyDog();

void setup()
{
    Serial.begin(9600);
    dog.start();
    /*
        for (int i = 0; i < 4; i++)
        {
            dog.leg_list[i].move_shoulder(0);
            delay(100);
        } */
}

void loop()
{
    dog.move_aside();
}
