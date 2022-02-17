#include <Arduino.h>
#include "PolyDog/PolyDog.h"


PolyDog dog = PolyDog();

void setup()
{
    Serial.begin(9600);
    dog.start();
    Serial.println("oui");

}

void loop()
{
    dog.move_forward();
    Serial.println("ok");
    
}

