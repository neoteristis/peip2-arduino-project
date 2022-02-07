/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022 
  Released into the public domain.
*/

#include <Arduino.h>
#include <CustomServos.h>
#include <PolyDog.h>

PolyDog::PolyDog(int i)
{
    _i = i;
}

void PolyDog::forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int offset_hanche, int offset_genou)
{
    int delay_time = 300;

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));

    // Lift leg
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 30));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 85));

    // Start the knee to go down
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 45));

    // Start position again
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 77));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 38));

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));
}

void PolyDog::hold_shoulders(CustomServos shoulderA, CustomServos shoulderB, CustomServos shoulderC, CustomServos shoulderD)
{
    shoulderA.write(48);
    shoulderB.write(79);
    shoulderC.write(158);
    shoulderD.write(89);
}