#include <Arduino.h>
#include <PolyDog.h>
#include <CustomServos.h>

CustomServos servo1 = CustomServos();

void setup()
{
    // dog.start();
    // dog.attach_all_motors();
    Serial.begin(9600);
}

void loop()
{
    //dog.move_forward();
    control_two_with_potentio(CustomServos servo2, int pin_potentio1, int pin_potentio2, char const *name2)
    
}