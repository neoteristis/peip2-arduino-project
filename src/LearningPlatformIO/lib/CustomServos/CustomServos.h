#ifndef CUSTOM_SERVOS_H
#define CUSTOM_SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class CustomServos
{
public:
    CustomServos(int pin = 1);
    void write(int angle);
    void attach();
    void control_with_potentio(int pin_potentio);
    void control_two_with_potentio(CustomServos servo2, int pin_potentio1,
                                   int pin_potentio2);

    void move(int position, int time);

private:
    int _pin;
    Servo _servo;
};

#endif