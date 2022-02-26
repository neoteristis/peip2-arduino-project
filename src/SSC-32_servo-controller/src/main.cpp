#include <Arduino.h>
#include "PolyDog/PolyDog.h"
#include "CustomServos/CustomServos.h"
#include "Leg/Leg.h"
#include <IRremote.h>

// ----- PIXY RELATED -----
#include <Pixy2.h>
#include <PIDLoop.h>

Pixy2 pixy;
PIDLoop panLoop(400, 0, 400, true);
PIDLoop tiltLoop(500, 0, 500, true);
// ------------------------

PolyDog dog = PolyDog();
int IrReceiverPin = 8;
decode_results results;
IRrecv irrecv(IrReceiverPin);

int remote_choice = 0; // DEFAULT CHOICE : ROBOT IS STATIC

void setup()
{
    Serial.begin(115200); // TODO : change the serial value of the card
    dog.start();
    irrecv.enableIRIn();

    // ----- PIXY RELATED -----
    // We need to initialize the pixy object
    pixy.init();
    // Use color connected components program for the pan tilt to track
    pixy.changeProg("color_connected_components");
    // ------------------------
}

void loop()
{

    if (irrecv.decode(&results))
    {

        // Serial.println(results.value, HEX);

        irrecv.resume();

        switch (results.value)
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
    }

    delay(100);

    switch (remote_choice)
    {
    case 0:
        // ROBOT IS STATIC
        dog.start();
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10: // * button
        // The robot is in a waiting movement, juste like a game player waiting
        dog.self_balancing();
        break;
    case 11: // # button
        // The robot is doing a little excitement thing
        dog.excitment();
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
        break;
    case 16: // OK button
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
            // panLoop.reset();
            // tiltLoop.reset();
            // pixy.setServos(panLoop.m_command, tiltLoop.m_command);
        }

        break;
    default:
        break;
    }
}