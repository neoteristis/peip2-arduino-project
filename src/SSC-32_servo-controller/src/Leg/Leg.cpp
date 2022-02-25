#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "Leg.h"

Leg::Leg(int leg_number)
{
    _leg_number = leg_number;

    switch (_leg_number)
    {
    case 1:
        _knee_servo = SERVO_GENOU_A;
        _hip_servo = SERVO_HANCHE_A;
        _shoulder_servo = SERVO_EPAULE_A;
        _knee_offset = OFFSET_GENOU_A;
        _hip_offset = OFFSET_HANCHE_A;
        _shoulder_offset = OFFSET_EPAULE_A;
        _ANGLE_MIN_SHOULDER = -40; // BROKEN
        _ANGLE_MAX_SHOULDER = 132;
        break;

    case 2:
        _knee_servo = SERVO_GENOU_B;
        _hip_servo = SERVO_HANCHE_B;
        _shoulder_servo = SERVO_EPAULE_B;
        _knee_offset = OFFSET_GENOU_B;
        _hip_offset = OFFSET_HANCHE_B;
        _shoulder_offset = OFFSET_EPAULE_B;
        _ANGLE_MIN_SHOULDER = 165;
        _ANGLE_MAX_SHOULDER = -15;
        break;

    case 3:
        _knee_servo = SERVO_GENOU_C;
        _hip_servo = SERVO_HANCHE_C;
        _shoulder_servo = SERVO_EPAULE_C;
        _knee_offset = OFFSET_GENOU_C;
        _hip_offset = OFFSET_HANCHE_C;
        _shoulder_offset = OFFSET_EPAULE_C;
        _ANGLE_MIN_SHOULDER = 40;
        _ANGLE_MAX_SHOULDER = 270;
        break;

    case 4:
        _knee_servo = SERVO_GENOU_D;
        _hip_servo = SERVO_HANCHE_D;
        _shoulder_servo = SERVO_EPAULE_D;
        _knee_offset = OFFSET_GENOU_D;
        _hip_offset = OFFSET_HANCHE_D;
        _shoulder_offset = OFFSET_EPAULE_D;
        _ANGLE_MIN_SHOULDER = 0;
        _ANGLE_MAX_SHOULDER = 180;
        break;

    default:
        break;
    }
}

int Leg::get_hip_offset()
{
    return _hip_offset;
}

int Leg::get_knee_offset()
{
    return _knee_offset;
}

int Leg::get_shoulder_offset()
{
    return _shoulder_offset;
}

void Leg::move_knee(int angle)
{
    _knee_servo.write(abs(_knee_offset - angle));
}

void Leg::move_hip(int angle)
{
    _hip_servo.write(abs(_hip_offset - angle));
}

void Leg::move_shoulder(int angle)
{
    _shoulder_servo.write(map(angle, 0, 180, _ANGLE_MIN_SHOULDER, _ANGLE_MAX_SHOULDER));
}