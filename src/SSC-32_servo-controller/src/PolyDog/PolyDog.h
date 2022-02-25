#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "Leg/Leg.h"

class PolyDog
{
public:
    PolyDog(); // Default construteur
    void start();
    void forward_leg(int leg_number, int step);
    void hold_shoulders();
    void move_forward();
    void forward_leg2(int leg_number, int step);
    void move_forward2();

    Leg legA;
    Leg legB;
    Leg legC;
    Leg legD;
    Leg leg_list[4] = {legA, legB, legC, legD};

private:
};

#endif