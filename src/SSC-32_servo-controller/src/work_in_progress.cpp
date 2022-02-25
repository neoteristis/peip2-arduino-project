#include <Arduino.h>
/*
#include "PolyDog/PolyDog.h"
#include "CustomServos/CustomServos.h"
#include "Leg/Leg.h" */
#include <IRremote.h>

// PolyDog dog = PolyDog();
int IrReceiverPin = 2;
decode_results results;
IRrecv irrecv(IrReceiverPin);

int remote_choice;

void setup()
{
    Serial.begin(9600);
    // dog.start();
    irrecv.enableIRIn();
}

void loop()
{
    remote_choice = 0; // DEFAULT CHOICE : ROBOT IS STATIC

    if (irrecv.decode(&results))
    {

        // Serial.println(results.value, HEX);

        irrecv.resume();

        switch (results.value)
        {

        case 0xFF629D: // button UP
            Serial.println("BOUTON UP");
            break;
        case 0xFFC23D: // button RIGHT
            Serial.println("BOUTON RIGHT");
            break;
        case 0xFFA857: // button BOTTOM
            Serial.println("BOUTON BOTTOM");
            break;
        case 0xFF22DD: // button LEFT
            Serial.println("BOUTON LEFT");
            break;
        case 0xFF02FD: // button CENTER
            Serial.println("BOUTON CENTER");
            break;
        case 0xFF6897: // button 1
            Serial.println("BOUTON 1");
            break;
        case 0xFF9867: // button 2
            Serial.println("BOUTON 2");
            break;
        case 0xFFB04F: // button 3
            Serial.println("BOUTON 3");
            break;
        case 0xFF30CF: // button 4
            Serial.println("BOUTON 4");
            break;
        case 0xFF18E7: // button 5
            Serial.println("BOUTON 5");
            break;
        case 0xFF7A85: // button 6
            Serial.println("BOUTON 6");
            break;
        case 0xFF10EF: // button 7
            Serial.println("BOUTON 7");
            break;
        case 0xFF38C7: // button 8
            Serial.println("BOUTON 8");
            break;
        case 0xFF5AA5: // button 9
            Serial.println("BOUTON 9");
            break;
        case 0xFF42BD: // button *
            Serial.println("BOUTON *");
            break;
        case 0xFF4AB5: // button 0
            Serial.println("BOUTON 0");
            break;
        case 0xFF52AD: // button #
            Serial.println("BOUTON #");
            break;
        }
    }

    delay(100);

    switch (remote_choice)
    {
    case 0:
        // ROBOT IS STATIC
        break;
    case 1:
        // The dog is "crawling"
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
        break;
    case 11: // # button
        // The robot is doing a little excitement thing
        break;
    case 12: // UP button
        // The robot is going forward
        break;
    case 13: // RIGHT button
        // The robot is going to the right
        break;
    case 14: // DOWN button
        // The robot is going backward
        break;
    case 15: // LEFT button
        // The robot is going to the left
        break;
    case 16: // OK button
        // Camera mode : the dog is following an object
        break;
    default:
        break;
    }
}