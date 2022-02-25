#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "Leg.h"

Leg::Leg()
{
    // HOLDER
}

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
        break;

    case 2:
        _knee_servo = SERVO_GENOU_B;
        _hip_servo = SERVO_HANCHE_B;
        _shoulder_servo = SERVO_EPAULE_B;
        _knee_offset = OFFSET_GENOU_B;
        _hip_offset = OFFSET_HANCHE_B;
        _shoulder_offset = OFFSET_EPAULE_B;
        break;

    case 3:
        _knee_servo = SERVO_GENOU_C;
        _hip_servo = SERVO_HANCHE_C;
        _shoulder_servo = SERVO_EPAULE_C;
        _knee_offset = OFFSET_GENOU_C;
        _hip_offset = OFFSET_HANCHE_C;
        _shoulder_offset = OFFSET_EPAULE_C;
        break;

    case 4:
        _knee_servo = SERVO_GENOU_D;
        _hip_servo = SERVO_HANCHE_D;
        _shoulder_servo = SERVO_EPAULE_D;
        _knee_offset = OFFSET_GENOU_D;
        _hip_offset = OFFSET_HANCHE_D;
        _shoulder_offset = OFFSET_EPAULE_D;
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
    _shoulder_servo.write(abs(angle));
}