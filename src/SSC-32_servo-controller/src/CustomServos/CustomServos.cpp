/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include "CustomServos.h"

CustomServos::CustomServos(int pin)
{
  _pin = pin;
}

void CustomServos::write(int angle)
{
  this->move(map(angle, 0, 180, 500, 2500), 0);
}

void CustomServos::move(int position, int time)
{
  Serial.print("#");
  Serial.print(this->_pin);
  Serial.print(" P");
  Serial.print(position);
  Serial.print(" T");
  Serial.println(time);
  delay(time);
}