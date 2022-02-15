
/*
#include <Arduino.h>
#include <PolyDog.h>
#include <CustomServos.h>

// Leg that will run with the potentio in mode 0-0

int mode = 0;       // 0 : testing | 1 : full robot
int demo = 0;       // 0 : no leg demo | 1 : one leg demo
int leg_chosen = 1; // leg that will run for the demo

PolyDog dog = PolyDog();

void setup()
{
    if (mode == 0)
    {
        dog.attach_one_leg(leg_chosen);
        pinMode(26, INPUT);
        pinMode(27, INPUT);
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
        dog.control_leg_with_potentio(leg_chosen, 26, 27);

        if (demo == 1)
        {
            int number_of_stages = 7;
            for (int stage = 1; stage < number_of_stages + 1; stage++)
            {
                dog.forward_leg(leg_chosen, stage % number_of_stages); // 180 for A and D
                delay(100);
            }
        }
    }
    else
    {
        // dog.control_leg_with_potentio(1, 2, 3);
        // dog.move_forward();
        // dog.start();
        // dog.forward_leg(1, 16, 180, 180);
    }
}*/