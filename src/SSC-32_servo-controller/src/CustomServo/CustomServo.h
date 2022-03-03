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

/**
 * @file CustomServo.h
 *
 * @brief CustomServo object can control a servo motor using the lynx-motion protocol
 *
 * @authors ANJOU Raphael & DURAND Hugo
 * <p>
 * Contact: anjou.raphael\@gmail.com | hugo.durand971\@gmail.com
 *
 */

#ifndef CUSTOM_SERVO_H
#define CUSTOM_SERVO_H

#include <Arduino.h>

/**
 * A {@code CustomServo} object allows you to control a servo motor using the lynx-motion protocol
 * It is using serial communication to give the instruction.
 *
 * In our case we are always using : "#{@code PIN} P{@code VALUE} T0"
 * Where {@code PIN} is the pin controlling the servo and VALUE is an integer between 500 and 2500 equivalent to an
 * angle between 0 and 180.
 *
 * @authors ANJOU Raphael & DURAND Hugo
 */
class CustomServo
{
public:
    /**
     * This method is the {@code CustomServo} initializer
     *
     * @param pin the pin to which the servo motor is connected
     * @author ANJOU Raphael
     */
    CustomServo(int pin = 1);
    /**
     * This method will write the angle given to the servo
     *
     * @param angle the angle to move the servo to
     * @author DURAND Hugo
     */
    void write(int angle);
    /**
     * This method manages the serial communication to move a servo motor.
     *
     * @param position the value between 500 and 2500 equivalent to an angle between 0 and 180
     * @param time the duration that the servo needs to respect when moving between current and final positions
     * @author DURAND Hugo
     */
    void move(int position, int time);

private:
    int _pin;
};

#endif