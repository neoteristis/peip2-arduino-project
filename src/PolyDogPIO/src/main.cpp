#include <Arduino.h>
#include <PolyDog.h>

#include <CustomServos.h>
CustomServos servo_hanche(30, "G");
CustomServos servo_genou(31, "H");

int mode = 1;
int demo = 1;
int leg_chosen = 1;

PolyDog dog = PolyDog();

/* void setup()
{
    dog.attach_all_motors();
}

void loop()
{
    dog.start();
} */

void setup()
{
    if (mode == 0)
    {
        servo_hanche.attach();
        servo_genou.attach();
        if (demo == 1)
        {
            dog.attach_one_leg(leg_chosen);
        }
    }
    else
    {
        dog.start();
        dog.attach_all_motors();
    }

    Serial.begin(9600);
}

void loop()
{
    if (mode == 0)
    {
        servo_hanche.control_two_with_potentio(servo_genou, 2, 3);

        if (demo == 1)
        {
            int number_of_stages = 7;
            for (int stage = 1; stage < number_of_stages + 1; stage++)
            {
                dog.forward_leg(leg_chosen, stage % number_of_stages, 180, 180); // 180 for A and D
                delay(100);
            }
        }
    }
    else
    {
        // dog.control_leg_with_potentio(1, 2, 3);
        dog.move_forward();
    }
}
