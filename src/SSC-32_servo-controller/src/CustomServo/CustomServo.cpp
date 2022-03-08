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
#include "CustomServo.h"

/**
 * This method is the {@code CustomServo} initializer
 *
 * @param pin the pin to which the servo motor is connected
 * @author ANJOU Raphael
 */
CustomServo::CustomServo(int pin)
{
  _pin = pin;
}

/**
 * This method will move the servo motor to the desired angle.
 *
 * The input is a value between 0 and 180. This value is mapped between 500 and 2500 to correspond with the lynx-motion
 * protocol.
 *
 * @param angle the desired angle for the servo motor
 * @author DURAND Hugo
 */
void CustomServo::write(int angle)
{
  move(map(angle, 0, 180, 500, 2500), 0);
}

/**
 * This method manages the serial communication to move a servo motor.
 *
 * @param position the value between 500 and 2500 equivalent to an angle between 0 and 180
 * @param time the duration that the servo needs to respect when moving between current and final positions
 * @author DURAND Hugo
 */
void CustomServo::move(int position, int time)
{
  Serial.print("#");
  Serial.print(_pin);
  Serial.print(" P");
  Serial.print(position);
  Serial.print(" T");
  Serial.println(time);
  delay(time);
}