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
#include "PolyDog/PolyDog.h"
#include "CustomServo/CustomServo.h"
#include "Leg/Leg.h"
#include <IRremote.h>
#include <Pixy2.h>
#include <PIDLoop.h>

// ------ INITIALIZATION ------
Pixy2 pixy;
PIDLoop panLoop(400, 0, 400, true);
PIDLoop tiltLoop(500, 0, 500, true);

PolyDog dog = PolyDog();

int IrReceiverPin = 8;
decode_results results;
IRrecv IRreceiver(IrReceiverPin);

int remote_choice = 0; // Default choice : robot is standing and not moving
// ------ END OF INITIALIZATION ------

/**
 * This method translates the button pushed on the remote to a number that can then be used to know which method
 * needs to be execute in the main loop. Assigning the choice to a variable makes it possible to push a button only once
 * and still have the method running in the main loop.
 *
 * @param results the data received by the infrared receiver
 * @return a number between 0 and 16 which is later used to decide which method needs to be called
 */
int getRemoteChoice(uint32_t results)
{
    switch (results)
    {

    case 0xFF629D: // button UP
        remote_choice = 12;
        break;
    case 0xFFC23D: // button RIGHT
        remote_choice = 13;
        break;
    case 0xFFA857: // button BOTTOM
        remote_choice = 14;
        break;
    case 0xFF22DD: // button LEFT
        remote_choice = 15;
        break;
    case 0xFF02FD: // button CENTER
        remote_choice = 16;
        break;
    case 0xFF6897: // button 1
        remote_choice = 1;
        break;
    case 0xFF9867: // button 2
        remote_choice = 2;
        break;
    case 0xFFB04F: // button 3
        remote_choice = 3;
        break;
    case 0xFF30CF: // button 4
        remote_choice = 4;
        break;
    case 0xFF18E7: // button 5
        remote_choice = 5;
        break;
    case 0xFF7A85: // button 6
        remote_choice = 6;
        break;
    case 0xFF10EF: // button 7
        remote_choice = 7;
        break;
    case 0xFF38C7: // button 8
        remote_choice = 8;
        break;
    case 0xFF5AA5: // button 9
        remote_choice = 9;
        break;
    case 0xFF42BD: // button *
        remote_choice = 10;
        break;
    case 0xFF4AB5: // button 0
        remote_choice = 0;
        break;
    case 0xFF52AD: // button #
        remote_choice = 11;
        break;
    }

    return remote_choice;
}

/**
 * This method is executed only once at the beginning of the program.
 * It initialize the Serial communication (baud rate = 115200), the PolyDog instance, the infrared communication and the
 * Pixy Cam.
 */
void setup()
{
    dog.start();
    Serial.begin(115200);
    IRreceiver.enableIRIn();

    pixy.init();
    pixy.changeProg("color_connected_components");
}

/**
 * This method is a loop that is executed infinitely right after the setup(). It manages the logic of which method is
 * executed by the robot. It also reads the value from the infrared remote.
 */
void loop()
{
    // dog.start();
    // dog.move_forward();
    dog.control_with_potentio();
    // dog.sweep_every_servo();

    /**
    if (IRreceiver.decode())
    {
        IRreceiver.resume();
        remote_choice = getRemoteChoice(IrReceiver.decodedIRData.decodedRawData);
    }

    delay(100);

    switch (remote_choice)
    {
    case 0: // button 0
            // Camera mode : the dog is following an object

        int32_t panOffset, tiltOffset;

        // get active blocks from Pixy
        pixy.ccc.getBlocks();

        if (pixy.ccc.numBlocks)
        {

            // calculate pan and tilt "errors" with respect to first object (blocks[0]),
            // which is the biggest object (they are sorted by size).
            panOffset = (int32_t)pixy.frameWidth / 2 - (int32_t)pixy.ccc.blocks[0].m_x;
            tiltOffset = (int32_t)pixy.ccc.blocks[0].m_y - (int32_t)pixy.frameHeight / 2;

            // update loops
            panLoop.update(panOffset);
            tiltLoop.update(tiltOffset);

            // set pan and tilt servos
            pixy.setServos(panLoop.m_command, tiltLoop.m_command);

            dog.move_forward();
        }
        else // no object detected, go into reset state
        {
            panLoop.reset();
            tiltLoop.reset();
            pixy.setServos(panLoop.m_command, tiltLoop.m_command);
        }

        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    case 10: // * button
        // The robot is in a waiting movement, juste like a game player waiting
        dog.self_balancing();
        break;
    case 11: // # button
        // The robot is doing a little excitement thing
        dog.excitement();
        break;
    case 12: // UP button
        // The robot is going forward
        dog.move_forward();
        break;
    case 13: // RIGHT button
        // The robot is going to the right
        dog.move_right();
        break;
    case 14: // DOWN button
        // The robot is going backward
        break;
    case 15: // LEFT button
        // The robot is going to the left
        dog.move_left();
        break;
    case 16: // OK button
        // ROBOT IS STATIC
        dog.start();
        break;
    default:
        break;
    }**/
}
