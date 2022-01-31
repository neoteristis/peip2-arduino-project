/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022 
  Released into the public domain.
*/

#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>

CustomServos::CustomServos(int pin, int angle_min, int angle_max)
{
    _pin = pin;
    _angle_min = angle_min;
    _angle_max = angle_max;
}

void CustomServos::max_rotation()
{
    _servo.write(_angle_max);
}

void CustomServos::min_rotation()
{
    _servo.write(_angle_min);
}

void CustomServos::write(int angle)
{
    _servo.write(angle);
}

void CustomServos::attach()
{
    _servo.attach(_pin);
}
