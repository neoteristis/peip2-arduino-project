// Copyright (c) 2022-2022. ANJOU Raphaël & DURAND Hugo
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <Arduino.h>
#include "CustomServo/CustomServo.h"
#include "Leg/Leg.h"

/**
 * This method will initialize a {@code Leg} object.
 * It uses {@code leg_number} to know which motors and constants need to be assigned to the object.
 *
 * @param leg_number this number will tell which leg of the robot needs to be used. This will affect minimum and maximum
 * values as well as offset
 * @author ANJOU Raphael
 */
Leg::Leg(int leg_number)
{
    _leg_number = leg_number;

    switch (_leg_number)
    {
    case 1:
        _knee_servo = SERVO_KNEE_A;
        _hip_servo = SERVO_HIP_A;
        _shoulder_servo = SERVO_SHOULDER_A;
        _knee_offset = OFFSET_KNEE_A;
        _hip_offset = OFFSET_HIP_A;
        _ANGLE_MIN_SHOULDER = ANGLE_MIN_SHOULDER_A;
        _ANGLE_MAX_SHOULDER = ANGLE_MAX_SHOULDER_A;
        break;

    case 2:
        _knee_servo = SERVO_KNEE_B;
        _hip_servo = SERVO_HIP_B;
        _shoulder_servo = SERVO_SHOULDER_B;
        _knee_offset = OFFSET_KNEE_B;
        _hip_offset = OFFSET_HIP_B;
        _ANGLE_MIN_SHOULDER = ANGLE_MIN_SHOULDER_B;
        _ANGLE_MAX_SHOULDER = ANGLE_MAX_SHOULDER_B;
        break;

    case 3:
        _knee_servo = SERVO_KNEE_C;
        _hip_servo = SERVO_HIP_C;
        _shoulder_servo = SERVO_SHOULDER_C;
        _knee_offset = OFFSET_KNEE_C;
        _hip_offset = OFFSET_HIP_C;
        _ANGLE_MIN_SHOULDER = ANGLE_MIN_SHOULDER_C;
        _ANGLE_MAX_SHOULDER = ANGLE_MAX_SHOULDER_C;
        break;

    case 4:
        _knee_servo = SERVO_KNEE_D;
        _hip_servo = SERVO_HIP_D;
        _shoulder_servo = SERVO_SHOULDER_D;
        _knee_offset = OFFSET_KNEE_D;
        _hip_offset = OFFSET_HIP_D;
        _ANGLE_MIN_SHOULDER = ANGLE_MIN_SHOULDER_D;
        _ANGLE_MAX_SHOULDER = ANGLE_MAX_SHOULDER_D;
        break;

    default:
        break;
    }
}

/**
 * This method will move the knee to the desired angle.
 *
 * The class value _knee_offset allows us to give the same angle to all motors.
 * If it was not there, motors that are upside down would be going in the opposite direction of the others.
 *
 * @param angle the angle wanted for the servo
 * @author ANJOU Raphael
 */
void Leg::move_knee(int angle, int offset)
{
    // _knee_servo.write(abs(_knee_offset - angle));
    _knee_servo.write(abs(offset - angle));
}

void Leg::move_knee(int angle)
{
    _knee_servo.write(abs(_knee_offset - angle));
}

/**
 * This method will move the hip to the desired angle.
 *
 * The class value _hip_offset allows us to give the same angle to all motors.
 * If it was not there, motors that are upside down would be going in the opposite direction of the others.
 *
 * @param angle the angle wanted for the servo
 * @author ANJOU Raphael
 */
void Leg::move_hip(int angle, int offset)
{
    // _hip_servo.write(abs(_hip_offset - angle));
    _hip_servo.write(abs(offset - angle));
}

void Leg::move_hip(int angle)
{
    _hip_servo.write(abs(_hip_offset - angle));
}

/**
 * This method will move the shoulder to the desired angle.
 *
 * _ANGLE_MIN_SHOULDER and _ANGLE_MAX_SHOULDER are values that needs to be manually written.
 * The first one corresponds to the angle where the leg is parallel to the ground and facing upward.
 * The second one corresponds to the angle where the leg is parallel to the ground and facing downward.
 * Therefore, thanks to this calibration, 90° will always be the value where the leg is perpendicular to the ground.
 *
 * @param angle the angle wanted for the servo
 * @author ANJOU Raphael
 */
void Leg::move_shoulder(int angle)
{
    _shoulder_servo.write(map(angle, 0, 180, _ANGLE_MIN_SHOULDER, _ANGLE_MAX_SHOULDER));
}
