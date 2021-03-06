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
#include "PolyDog/PolyDog.h"
#include "Leg/Leg.h"

/**
 * This method is the {@code PolyDog} initializer.
 * It is just creating the {@code Leg} instances.
 *
 * @author ANJOU Raphael
 */
PolyDog::PolyDog() : legA(1), legB(2), legC(3), legD(4)
{
    // HOLDER
}

/**
 * This method places the robot in an upright stable position.
 * <p>
 * This method takes a minimum of 400ms to execute due to 4 delays of 100ms.
 * <p>
 * The algorithm just consists in moving every knee and hip motors to the desired value.
 *
 * @author ANJOU Raphael
 */
void PolyDog::start()
{
    for (int i = 0; i < 4; i++)
    {
        leg_list[i].move_hip(90);
        leg_list[i].move_knee(90);
        delay(100);
    }

    this->hold_shoulders();
}

/**
 * This method place the shoulder in a position where all legs are perpendicular to the ground.
 * <p>
 * There are no delays in this methods. It might be necessary to put some delay after executing it if the shoulders
 * need to move right after.
 * <p>
 * The algorithm consists in placing all shoulder motors at a 90 degrees angle.
 *
 * @author ANJOU Raphael
 */
void PolyDog::hold_shoulders()
{
    legA.move_shoulder(90);
    legB.move_shoulder(90);
    legC.move_shoulder(90);
    legD.move_shoulder(90);
}

/**
 * This method moves the robot body from left to right using only his shoulders.
 * If placed in a loop, it creates a nice waiting animation.
 * <p>
 * This method takes a minimum of 800ms to execute due to 40 delays of 20ms.
 * <p>
 * The algorithm consists of two loops, each one of 20 steps. They allow a smooth movement between two desired positions
 * of the robot. One of the loop moves it to the right, and the next one to the left.
 *
 * @author DURAND Hugo
 */
void PolyDog::self_balancing()
{

    for (int i = 0; i < 20; i++)
    {
        legA.move_shoulder(80 + i);
        legB.move_shoulder(100 - i);
        legC.move_shoulder(100 - i);
        legD.move_shoulder(80 + i);
        delay(20);
    }

    for (int i = 0; i < 20; i++)
    {
        legA.move_shoulder(100 - i);
        legB.move_shoulder(80 + i);
        legC.move_shoulder(80 + i);
        legD.move_shoulder(100 - i);
        delay(20);
    }
}

/**
 * This method moves only the leg A up and down once.
 * If placed in a loop, it creates a nice excitement like animation.
 * <p>
 * This method takes a minimum of 300ms to execute due to 2 delays of 150ms.
 * <p>
 * The algorithm is very simple. We are just moving the leg up a little bit, waiting, and moving it back to default
 * position.
 *
 * @author ANJOU Raphael & DURAND Hugo
 */
void PolyDog::excitement()
{
    legA.move_knee(60);
    legA.move_hip(50);

    delay(150);

    legA.move_knee(70);
    legA.move_hip(70);

    delay(150);
}

/**
 * This methods moves the robot one step forward.
 * If placed in a loop, the robot appears to be walking smoothly.
 * <p>
 * This method takes a minimum of 1300ms to execute due to 13 delays of 100ms.
 * <p>
 * The algorithm consists in moving each foot forward a little bit. When all of them are forward be make each leg come
 * back to their starting position.
 *
 * @author ANJOU Raphael & DURAND Hugo
 */
void PolyDog::move_forward()
{
    // To make sure that all legs are perpendicular to the ground
    hold_shoulders();

    // This loop will repeat the same movement for all four legs
    for (int i = 0; i < 4; i++)
    {
        delay(100);
        leg_list[i].move_hip(65);
        leg_list[i].move_knee(65);
        delay(100);
        leg_list[i].move_hip(75);
        leg_list[i].move_knee(50);
        delay(100);
        leg_list[i].move_hip(75);
        leg_list[i].move_knee(60);
    }

    delay(100);

    // This loop will repeat the same movement for all four legs
    for (int i = 0; i < 4; i++)
    {
        leg_list[i].move_hip(70);
        leg_list[i].move_knee(70);
    }
}

/**
 * This methods moves the robot one step to the right.
 * WARNING : It is still not working properly. The robot needs to be lifted a little bit to walk properly.
 * If placed in a loop, the robot appears to be walking sideways.
 * <p>
 * This method takes a minimum of 1400ms due to 12 delays of 100ms and 10 delays of 20ms
 * <p>
 * The algorithm consists of 3 main steps. First, we are moving leg B and leg C to the left one after the other. The
 * second step consists in moving shoulders B and C so that they are above their respective foot and moving shoulders A
 * and D to follow the body (all of the shoulders move simultaneously). Final step consists in bringing back the feet of
 * the legs B and C.
 *
 * @author ANJOU Raphael
 */
void PolyDog::move_right()
{
    // LEG A
    legA.move_hip(50);
    delay(100);
    legA.move_shoulder(70);
    delay(100);
    legA.move_hip(70);
    legA.move_knee(80);
    delay(100);

    // LEG D
    legD.move_hip(50);
    delay(100);
    legD.move_shoulder(70);
    delay(100);
    legD.move_hip(70);
    legD.move_knee(80);
    delay(100);

    // --- ALL LEGS SIMULTANEOUSLY ---
    for (int i = 1; i <= 10; i++)
    {
        legC.move_knee(70 + i);         // GOAL = 80
        legC.move_shoulder(90 - i * 2); // GOAL = 70

        legB.move_knee(70 + i);         // GOAL = 80
        legB.move_shoulder(90 - i * 2); // GOAL = 70

        legA.move_shoulder(70 + i * 2); // GOAL = 90
        legA.move_knee(80 - i);         // GOAL = 70

        legD.move_shoulder(70 + i * 2); // GOAL = 90
        legD.move_knee(80 - i);         // GOAL = 70

        delay(20);
    }

    // LEG C
    legC.move_hip(50);
    delay(100);
    legC.move_shoulder(90);
    delay(100);
    legC.move_hip(70);
    legC.move_knee(80);
    delay(100);

    // LEG B
    legB.move_hip(50);
    delay(100);
    legB.move_shoulder(90);
    delay(100);
    legB.move_hip(70);
    legB.move_knee(80);
    delay(100);
}

// ------------------------------------------------

/**
 * This methods moves the robot one step to the left.
 * WARNING : It is still not working properly. The robot needs to be lifted a little bit to walk properly.
 * If placed in a loop, the robot appears to be walking sideways.
 * <p>
 * This method takes a minimum of 1400ms due to 12 delays of 100ms and 10 delays of 20ms
 * <p>
 * The algorithm consists of 3 main steps. First, we are moving leg C and leg B to the left one after the other. The
 * second step consists in moving shoulders A and D so that they are above their respective foot and moving shoulders B
 * and C to follow the body (all of the shoulders move simultaneously). Final step consists in bringing back the feet of
 * the legs A and D.
 *
 * @author ANJOU Raphael
 */
void PolyDog::move_left()
{
    // LEG C
    legC.move_hip(50);
    delay(100);
    legC.move_shoulder(70);
    delay(100);
    legC.move_hip(70);
    legC.move_knee(80);
    delay(100);

    // LEG B
    legB.move_hip(50);
    delay(100);
    legB.move_shoulder(70);
    delay(100);
    legB.move_hip(70);
    legB.move_knee(80);
    delay(100);

    // --- ALL LEGS SIMULTANEOUSLY ---
    for (int i = 1; i <= 10; i++)
    {
        legA.move_knee(70 + i);         // GOAL = 80
        legA.move_shoulder(90 - i * 2); // GOAL = 70

        legD.move_knee(70 + i);         // GOAL = 80
        legD.move_shoulder(90 - i * 2); // GOAL = 70

        legC.move_shoulder(70 + i * 2); // GOAL = 90
        legC.move_knee(80 - i);         // GOAL = 70

        legB.move_shoulder(70 + i * 2); // GOAL = 90
        legB.move_knee(80 - i);         // GOAL = 70

        delay(20);
    }

    // LEG A
    legA.move_hip(50);
    delay(100);
    legA.move_shoulder(90);
    delay(100);
    legA.move_hip(70);
    legA.move_knee(80);
    delay(100);

    // LEG D
    legD.move_hip(50);
    delay(100);
    legD.move_shoulder(90);
    delay(100);
    legD.move_hip(70);
    legD.move_knee(80);
    delay(100);
}

void PolyDog::sweep_every_servo()
{
    legA.move_hip(180);
    legB.move_hip(180);
    legC.move_hip(180);
    legD.move_hip(180);
    legA.move_knee(180);
    legB.move_knee(180);
    legC.move_knee(180);
    legD.move_knee(180);
    legA.move_shoulder(180);
    legB.move_shoulder(180);
    legC.move_shoulder(180);
    legD.move_shoulder(180);
    delay(2000);
    legA.move_hip(0);
    legB.move_hip(0);
    legC.move_hip(0);
    legD.move_hip(0);
    legA.move_shoulder(0);
    legB.move_shoulder(0);
    legC.move_shoulder(0);
    legD.move_shoulder(0);
    legA.move_knee(0);
    legB.move_knee(0);
    legC.move_knee(0);
    legD.move_knee(0);
    delay(2000);
}

void PolyDog::middle_every_servo()
{
    for (int i = 0; i < 4; i++)
    {
        leg_list[i].move_hip(90);
        leg_list[i].move_knee(90);
        leg_list[i].move_shoulder(90);
        delay(15);
    }
    delay(2000);
}

void PolyDog::control_with_potentio()
{
    int val_knee;
    int val_hip;

    val_knee = analogRead(A0);
    val_knee = map(val_knee, 0, 1023, 0, 180);

    val_hip = analogRead(A2);
    val_hip = map(val_hip, 0, 1023, 0, 180);

    for (int i = 0; i < 3; i++)
    {
        leg_list[i].move_hip(90);
        leg_list[i].move_knee(90);
        delay(10);
    }

    for (int j = 0; j < 20; j++)
    {
        for (int leg_number = 0; leg_number < 4; leg_number++)
        {
            leg_list[leg_number].move_hip(80 + j);
            leg_list[leg_number].move_knee(80 + j);
        }
        delay(15);
    }
    for (int j = 0; j < 20; j++)
    {
        for (int leg_number = 0; leg_number < 4; leg_number++)
        {
            leg_list[leg_number].move_hip(90 - j);
            leg_list[leg_number].move_knee(90 - j);
        }
        delay(15);
    }
    delay(1000);
}