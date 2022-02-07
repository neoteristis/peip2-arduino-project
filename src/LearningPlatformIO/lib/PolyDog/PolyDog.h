#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include <CustomServos.h>

class PolyDog
{
public:
    PolyDog(CustomServos servo_to_test);
    void function_test();

private:
    CustomServos _servo_to_test;
};

#endif