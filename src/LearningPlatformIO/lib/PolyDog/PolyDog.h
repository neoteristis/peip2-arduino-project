#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include <CustomServos.h>

class PolyDog
{
public:
    PolyDog(int i);
    void forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int offset_hanche, int offset_genou);
    void hold_shoulders(CustomServos shoulderA, CustomServos shoulderB, CustomServos shoulderC, CustomServos shoulderD);

private:
    int _i;
};

#endif