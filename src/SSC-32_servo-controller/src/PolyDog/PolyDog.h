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
    void forward_leg2(int leg_number, int step);
    void hold_shoulders();
    void move_forward();
    void move_forward2();
    void move_aside_leg(int leg_number, int step);
    void move_aside();
    void avancer_jambe_test(int leg_number);
    void avancer_test();
    void control_from_dog();
    void position_attente();

    Leg legA;
    Leg legB;
    Leg legC;
    Leg legD;

    Leg leg_list[4];

private:
};

#endif