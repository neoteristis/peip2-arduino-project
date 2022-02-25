#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "PolyDog/PolyDog.h"
#include "Leg/Leg.h"

PolyDog::PolyDog() : legA(1), legB(2), legC(3), legD(4)

{
    // HOLDER
}

void PolyDog::move_forward()
{
    // DEBUT (ACTUAL POSITION : 70 | 70)

    for (int i = 0; i < 4; i++)
    {
        delay(100);
        leg_list[i].move_hip(65);
        leg_list[i].move_knee(65);
        delay(100);
        leg_list[i].move_hip(75);
        leg_list[i].move_knee(50);
        delay(100);
        leg_list[i].move_hip(75);
        leg_list[i].move_knee(60);
    }

    delay(100);
    for (int i = 0; i < 4; i++)
    {
        leg_list[i].move_hip(70);
        leg_list[i].move_knee(70);
    }
    // delay(1000000000);
}

/*
void PolyDog::move_forward()
{
    int number_of_stages = 16;
    int decalage_A = 0;
    int decalage_B = 8;
    int decalage_C = 4;
    int decalage_D = 12;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        // delay(300);
        delay(100);
    }

    // delay(500);
} */

void PolyDog::forward_leg(int leg_number, int step)
{
    leg_number -= 1;
    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen

    if (step == 1)
    {
        leg_list[leg_number].move_hip(70);
        leg_list[leg_number].move_knee(70);
    }
    else if (step == 2)
    {
        leg_list[leg_number].move_hip(55);
        leg_list[leg_number].move_knee(45);
    }
    else if (step == 3)
    {
        leg_list[leg_number].move_hip(90);
        leg_list[leg_number].move_knee(50);
    }
    else if (step == 4)
    {
        leg_list[leg_number].move_hip(100);
        leg_list[leg_number].move_knee(70);
    }
}

void PolyDog::hold_shoulders()
{
    leg_list[0].move_shoulder(90); // LEG A
    leg_list[1].move_shoulder(90); // LEG B
    leg_list[2].move_shoulder(90); // LEG C
    leg_list[3].move_shoulder(90); // LEG D
}

void PolyDog::start()
{
    for (int i = 0; i < 4; i++)
    {
        leg_list[i].move_hip(70);
        leg_list[i].move_knee(70);
        delay(100);
    }

    this->hold_shoulders();
}

/*
void PolyDog::forward_leg2(int leg_number, int step)
{
    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen
    switch (step)
    {
    default:
    case 1:
        leg_list[leg_number - 1].move_hip(70);
        leg_list[leg_number - 1].move_knee(70);
        break;

    case 2:
        leg_list[leg_number - 1].move_hip(60);
        leg_list[leg_number - 1].move_knee(45);

    case 3:
        leg_list[leg_number - 1].move_hip(90);
        leg_list[leg_number - 1].move_knee(60);

    case 4:
        leg_list[leg_number - 1].move_hip(70);s
        leg_list[leg_number - 1].move_knee(90);
    }
}

void PolyDog::move_forward2()
{
    int number_of_stages = 16;
    int decalage_A = 0;
    int decalage_B = 4;
    int decalage_C = 8;
    int decalage_D = 12;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        delay(300);
    }
}

*/