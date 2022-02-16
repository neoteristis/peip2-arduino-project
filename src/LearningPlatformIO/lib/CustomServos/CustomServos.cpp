/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>

CustomServos::CustomServos(int pin)
{
    _pin = pin;
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

void CustomServos::control_two_with_potentio(CustomServos servo2, int pin_potentio1, int pin_potentio2)
{
    int val_servo1 = map(analogRead(pin_potentio1), 0, 1023, 0, 180);
    int val_servo2 = map(analogRead(pin_potentio2), 0, 1023, 0, 180);

    _servo.write(val_servo1);
    servo2.write(val_servo2);

    Serial.print("Angle of servo01: '");
    Serial.print(val_servo1);
    Serial.print(" | Angle of servo02 : '");
    Serial.println(val_servo2);
}
