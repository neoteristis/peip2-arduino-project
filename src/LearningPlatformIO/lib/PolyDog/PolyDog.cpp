/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022 
  Released into the public domain.
*/

#include <Arduino.h>
#include <CustomServos.h>
#include <PolyDog.h>

PolyDog::PolyDog(CustomServos servo_to_test)
{
    _servo_to_test = servo_to_test;
}

void PolyDog::function_test()
{
    _servo_to_test.write(45);
    delay(500);
    _servo_to_test.write(90);
    delay(500);
}
