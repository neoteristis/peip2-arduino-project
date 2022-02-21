#include <Arduino.h>
#include "PolyDog/PolyDog.h"

PolyDog dog = PolyDog();

void setup()
{
    Serial.begin(9600);
    dog.start();
    delay(400);
}

void loop()
{
    dog.start();
    // dog.move_forward2();
    // dog.workout();
    // dog.hold_shoulders();
    //  dog.move_one_leg_correctly(2);
    //  dog.disable_all_motors();
}
