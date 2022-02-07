#ifndef CUSTOM_SERVOS_H
#define CUSTOM_SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class CustomServos
{
public:
    CustomServos(int pin = 1, char const *name = "servo", int angle_min = 0, int angle_max = 180);
    void max_rotation();
    void min_rotation();
    void amplitude_test();
    void write(int angle);
    void attach();
    void control_with_potentio(int pin_potentio1);
    void control_two_with_potentio(CustomServos servo2, int pin_potentio1,
                                   int pin_potentio2, char const *name02 = "servo02");

private:
    int _pin;
    String _name;
    int _angle_min;
    int _angle_max;
    Servo _servo;
};

#endif