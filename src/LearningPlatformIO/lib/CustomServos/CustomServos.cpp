/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022 
  Released into the public domain.
*/

#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>

CustomServos::CustomServos(int pin, char const *name, int angle_min, int angle_max)
{
    _pin = pin;
    _angle_min = angle_min;
    _angle_max = angle_max;
    _name = *name;
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

void CustomServos::control_with_potentio(int pin_potentio1)
{
    int val_servo1 = map(analogRead(pin_potentio1), 0, 1023, 0, 180);

    _servo.write(val_servo1);

    Serial.print("Angle of '");
    Serial.print(_name);
    Serial.print("' : ");
    Serial.println(val_servo1);
}

void CustomServos::control_two_with_potentio(CustomServos servo2, int pin_potentio1, int pin_potentio2, char const *name2)
{
    int val_servo1 = map(analogRead(pin_potentio1), 0, 1023, 0, 180);
    int val_servo2 = map(analogRead(pin_potentio2), 0, 1023, 0, 180);

    _servo.write(val_servo1);
    servo2.write(val_servo2);

    Serial.print("Angle of '");
    Serial.print(_name);
    Serial.print("' : ");
    Serial.print(val_servo1);
    Serial.print(" | Angle of '");
    Serial.print(*name2);
    Serial.print("' : ");
    Serial.println(val_servo2);
}
