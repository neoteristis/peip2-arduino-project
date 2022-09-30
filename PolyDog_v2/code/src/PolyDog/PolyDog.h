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
 * @file PolyDog.h
 *
 * @brief PolyDog object contains all methods to move the robot
 *
 * @authors ANJOU Raphael & DURAND Hugo
 * <p>
 * Contact: anjou.raphael\@gmail.com | hugo.durand971\@gmail.com
 *
 */

#ifndef POLY_DOG_H
#define POLY_DOG_H

#include <Arduino.h>
#include "CustomServo/CustomServo.h"
#include "Leg/Leg.h"

/**
 * A {@code CustomServo} object allows you to control the PolyDog robot and move it around.
 * Quite a few methods exists to control the robot.
 * Each leg can be controlled separately for specific movement.
 *
 * There are no parameters to initialize the robot.
 * You need to wire every servo to the correct pin specified in the {@code Leg} class.
 * You also need to verify that you mounted the motors correctly, description on how to do it can be found in the
 * documentation.
 *
 * @authors ANJOU Raphael & DURAND Hugo
 */
class PolyDog
{
public:
    /**
     * This method is the {@code PolyDog} initializer.
     * It is just creating the {@code Leg} instances.
     *
     * @author ANJOU Raphael
     */
    PolyDog();

    /**
     * This method places the robot in an upright stable position.
     *
     * @author ANJOU Raphael
     */
    void start();

    /**
     * This method place the shoulder in a position where all legs are perpendicular to the ground.
     *
     * @author ANJOU Raphael
     */
    void hold_shoulders();

    /**
     * This method moves the robot body from left to right using only his shoulders.
     * If placed in a loop, it creates a nice waiting animation.
     *
     * @author DURAND Hugo
     */
    void self_balancing();

    /**
     * This methods moves only the leg A up and down once.
     * If placed in a loop, it creates a nice excitement like animation.
     *
     * @authors ANJOU Raphael & DURAND Hugo
     */
    void excitement();

    /**
     * This methods moves the robot one step forward.
     * If placed in a loop, the robot appears to be walking smoothly.
     *
     * @authors ANJOU Raphael & DURAND Hugo
     */
    void move_forward();

    /**
     * This methods moves the robot one step to the right.
     * WARNING : It is still not working properly. The robot needs to be lifted a little bit to walk properly.
     * If placed in a loop, the robot appears to be walking sideways.
     *
     * @author ANJOU Raphael
     */
    void move_right();

    /**
     * This methods moves the robot one step to the left.
     * WARNING : It is still not working properly. The robot needs to be lifted a little bit to walk properly.
     * If placed in a loop, the robot appears to be walking sideways.
     *
     * @author ANJOU Raphael
     */
    void move_left();

    /**
     * @brief TO COMMENT
     */
    void sweep_every_servo();
    void middle_every_servo();
    void control_with_potentio();

    void move_leg(int i);

    Leg legA;
    Leg legB;
    Leg legC;
    Leg legD;
    Leg leg_list[4] = {legA, legB, legC, legD};

private:
};

#endif