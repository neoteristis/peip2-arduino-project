#ifndef LEG_H
#define LEG_H

#include <Arduino.h>
#include "CustomServos/CustomServos.h"

class Leg
{
public:
    // Leg();
    Leg(int leg_number);
    int get_knee_offset();
    int get_hip_offset();
    int get_shoulder_offset();
    void move_knee(int angle);
    void move_hip(int angle);
    void move_shoulder(int angle);

    // Constants for LEG A
    int OFFSET_GENOU_A = 165;
    int OFFSET_HANCHE_A = 165;
    int OFFSET_EPAULE_A = 42;

    // Constants for LEG B
    int OFFSET_GENOU_B = 0;
    int OFFSET_HANCHE_B = 0;
    int OFFSET_EPAULE_B = 74;

    // Constants for LEG C
    int OFFSET_GENOU_C = 0;
    int OFFSET_HANCHE_C = 0;
    int OFFSET_EPAULE_C = 154;

    // Constants for LEG D
    int OFFSET_GENOU_D = 165;
    int OFFSET_HANCHE_D = 165;
    int OFFSET_EPAULE_D = 91;

    CustomServos SERVO_EPAULE_A = CustomServos(8);
    CustomServos SERVO_HANCHE_A = CustomServos(9);
    CustomServos SERVO_GENOU_A = CustomServos(10);
    CustomServos SERVO_EPAULE_B = CustomServos(24);
    CustomServos SERVO_HANCHE_B = CustomServos(25);
    CustomServos SERVO_GENOU_B = CustomServos(26);
    CustomServos SERVO_EPAULE_C = CustomServos(23);
    CustomServos SERVO_HANCHE_C = CustomServos(22);
    CustomServos SERVO_GENOU_C = CustomServos(21);
    CustomServos SERVO_EPAULE_D = CustomServos(7);
    CustomServos SERVO_HANCHE_D = CustomServos(6);
    CustomServos SERVO_GENOU_D = CustomServos(5);

private:
    int _leg_number;
    CustomServos _knee_servo;
    CustomServos _hip_servo;
    CustomServos _shoulder_servo;
    int _knee_offset;
    int _hip_offset;
    int _shoulder_offset;
    int _ANGLE_MIN_SHOULDER;
    int _ANGLE_MAX_SHOULDER;
};
#endif