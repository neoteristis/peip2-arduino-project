/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022 
  Released into the public domain.
*/

#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>

CustomServos::CustomServos(int pin, char name, int angle_min, int angle_max)
{
    _pin = pin;
    _name = name;
    _angle_min = angle_min;
    _angle_max = angle_max;

    Servo _servo;
    _servo.attach(_pin);
}

void CustomServos::max_rotation()
{
    _servo.write(_angle_max);
}

void CustomServos::min_rotation()
{
    _servo.write(_angle_min);
}
