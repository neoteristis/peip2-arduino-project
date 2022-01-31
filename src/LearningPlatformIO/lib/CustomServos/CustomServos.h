#ifndef CUSTOM_SERVOS_H
#define CUSTOM_SERVOS_H

#include <Arduino.h>
#include <Servo.h>

class CustomServos
{
public:
    CustomServos(int pin, int angle_min, int angle_max);
    void max_rotation();
    void min_rotation();
    void amplitude_test();
    void calibration();
    void write_angle(int angle);

private:
    int _pin;
    int _angle_min;
    int _angle_max;
    Servo _servo;
};

#endif