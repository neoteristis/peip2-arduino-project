#ifndef LEG_H
#define LEG_H

#include <Arduino.h>
#include "CustomServos/CustomServos.h"

class Leg
{
public:
    Leg();
    Leg(int leg_number);
    CustomServos get_knee_servo();
    CustomServos get_hip_servo();
    CustomServos get_shoulder_servo();
    int get_knee_offset();
    int get_hip_offset();
    int get_shoulder_offset();

private:
    int _legNumber;
    CustomServos _kneeServo;
    CustomServos _hipServo;
    CustomServos _shoulderServo;
    int kneeOffset;
    int hipOffset;
    int shoulderOffset;
};
#endif