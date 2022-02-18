#ifndef CUSTOM_SERVOS_H
#define CUSTOM_SERVOS_H

#include <Arduino.h>

class CustomServos
{
public:
    CustomServos(int pin = 1);
    void write(int angle);
    void move(int position, int time);

private:
    int _pin;
};

#endif