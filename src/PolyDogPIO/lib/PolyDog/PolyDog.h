#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include <CustomServos.h>

class PolyDog
{
public:
    PolyDog(); // Default construteur
    void start();
    void forward_leg(int leg_number, int step, int offset_hanche, int offset_genou);
    void hold_shoulders();
    void attach_all_motors();
    void move_forward();
    void select_leg(int leg_number);
    void control_leg_with_potentio(int leg_number, int pin_potentio01, int pin_potentio02);
    void attach_one_leg(int leg_number);

private:
    CustomServos _servoEpauleA;
    CustomServos _servoHancheA;
    CustomServos _servoGenouA;

    CustomServos _servoEpauleB;
    CustomServos _servoHancheB;
    CustomServos _servoGenouB;

    CustomServos _servoEpauleC;
    CustomServos _servoHancheC;
    CustomServos _servoGenouC;

    CustomServos _servoEpauleD;
    CustomServos _servoHancheD;
    CustomServos _servoGenouD;
};

#endif