#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include <CustomServos.h>

class PolyDog
{
public:
    PolyDog();
    void start();
    void forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int offset_hanche, int offset_genou);
    void hold_shoulders();
    void attach_all_motors();
    void move_forward();

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