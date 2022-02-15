#include <Arduino.h>
#include <PolyDog.h>

PolyDog dog = PolyDog();

void setup()
{
    dog.start();
    dog.attach_all_motors();
    Serial.begin(9600);
}

void loop()
{
    //dog.move_forward();
    
}
