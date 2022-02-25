#include <Arduino.h>
#include "PolyDog/PolyDog.h"
#include "CustomServos/CustomServos.h"

PolyDog dog = PolyDog();
CustomServos servo_epaule= CustomServos(8);

void setup()
{
    Serial.begin(9600);
    dog.start();
    delay(400);
}

void loop()
{
    //dog.start();
    // dog.avancer_test();
    dog.move_aside();
    // dog.move_forward2();
    //dog.position_attente();
    // dog.hold_shoulders();
    //  dog.move_one_leg_correctly(2);
    //  dog.disable_all_motors();
    }
