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
    dog.move_forward2();
    //dog.workout();
    //dog.hold_shoulders();
    // dog.move_one_leg_correctly(2);
    // dog.disable_all_motors();
    // Serial.println("#4 P0 T1000");
    // Serial.println("#5 P0 T1000");
    // Serial.println("#6 P0 T1000");
    // Serial.println("#8 P0 T1000");
    // Serial.println("#9 P0 T1000");
    // Serial.println("#10 P0 T1000");
    // Serial.println("#20 P0 T1000");
    // Serial.println("#21 P0 T1000");
    // Serial.println("#22 P0 T1000");
    // Serial.println("#16 P0 T1000");
    // Serial.println("#17 P0 T1000");
    // Serial.println("#18 P0 T1000");
}
