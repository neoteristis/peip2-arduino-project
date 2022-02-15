/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>

CustomServos::CustomServos(int pin, char const *name)
{
    _pin = pin;
    _name = *name;
    _last_angle_written = 0;
}

void CustomServos::write(int angle)
{
    this->_servo.write(angle);
    this->_last_angle_written = angle;
}

void CustomServos::writeWithLoop(int angle)
{
    int start_angle = _last_angle_written;
    int delta_angle = abs(angle - start_angle);
    for (int i = 1; i <= delta_angle; i++)
    {
        this->write(start_angle + i);
        delay(10);
    }
}

void CustomServos::attach()
{
    this->_servo.attach(this->_pin);
}

void CustomServos::control_with_potentio(int pin_potentio1)
{
    int val_servo1 = map(analogRead(pin_potentio1), 0, 1023, 0, 180);

    _servo.write(val_servo1);

    Serial.print("Angle of '");
    Serial.print(this->_name);
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
    Serial.print(this->_name);
    Serial.print("' : ");
    Serial.print(abs(val_servo1));
    Serial.print(" | Angle of '");
    Serial.print(*name2);
    Serial.print("' : ");
    Serial.println(abs(val_servo2));
}

int CustomServos::read()
{
    return this->_last_angle_written;
}