#ifndef CUSTOM_SERVOS_H
#define CUSTOM_SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class CustomServos
{
public:
    CustomServos(int pin = 1, char const *name = "servo");
    void write(int angle);
    void writeWithLoop(int angle);
    void attach();
    void control_with_potentio(int pin_potentio1);
    void control_two_with_potentio(CustomServos servo2, int pin_potentio1,
                                   int pin_potentio2, char const *name02 = "servo02");
    int read();

private:
    int _pin;
    char _name;
    int _last_angle_written;
    Servo _servo;
};

#endif