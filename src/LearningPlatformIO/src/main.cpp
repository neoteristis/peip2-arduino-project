#include <Arduino.h>
#include <PolyDog.h>

PolyDog dog = PolyDog();

void setup()
{
    dog.start();
    Serial.begin(9600);
    Serial.println("oui");
}

void loop()
{
    dog.move_forward();
    Serial.println("ok");
    
}
