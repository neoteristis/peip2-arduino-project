#include <Arduino.h>
#include <PolyDog.h>
#include <CustomServos.h>

PolyDog dog = PolyDog();

void setup()
{
    dog.attach_all_motors();
    dog.start();
}

void loop()
{
    dog.move_forward();
    // for (int i = 0; i < 8; i++)
    // {
    //     dog.forward_leg(1, i, 180, 180);
    //     delay(300);
    // }

    delay(100);
}