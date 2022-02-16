/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include <CustomServos.h>
#include <PolyDog.h>

PolyDog::PolyDog() : _servoEpauleA(36),
                     _servoHancheA(35),
                     _servoGenouA(34),
                     _servoEpauleB(32),
                     _servoHancheB(31),
                     _servoGenouB(30),
                     _servoEpauleC(2),
                     _servoHancheC(3),
                     _servoGenouC(4),
                     _servoEpauleD(8),
                     _servoHancheD(7),
                     _servoGenouD(6),

{
    // HOLDER
}

void PolyDog::forward_leg(int leg_number, int step, int offset_hanche, int offset_genou)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
    }

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen
    switch (step)
    {
    case 1:
        // Start position
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;

    case 2:
        servo_genou.write(abs(offset_genou - 30));
        break;

    case 3:
        servo_hanche.write(abs(offset_hanche - 85));
        break;

    case 4:
        servo_hanche.write(abs(offset_hanche - 85));
        break;

    case 5:
        servo_genou.write(abs(offset_genou - 77));
        break;

    case 6:
        servo_hanche.write(abs(offset_hanche - 38));
        break;

    case 7:
        // Equal to start position
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;

    default:
        // Equal to start position
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;
    }
}

void PolyDog::hold_shoulders()
{
    _servoEpauleA.write(48);
    _servoEpauleB.write(79);
    _servoEpauleC.write(158);
    _servoEpauleD.write(89);
}

void PolyDog::attach_all_motors()
{
    _servoEpauleA.attach();
    _servoHancheA.attach();
    _servoGenouA.attach();

    _servoEpauleB.attach();
    _servoHancheB.attach();
    _servoGenouB.attach();

    _servoEpauleC.attach();
    _servoHancheC.attach();
    _servoGenouC.attach();

    _servoEpauleD.attach();
    _servoHancheD.attach();
    _servoGenouD.attach();
}

void PolyDog::start()
{
    int delay_time = 300;
    // Start position
    _servoHancheA.write(abs(180 - 42));
    _servoGenouA.write(abs(180 - 85));

    _servoHancheB.write(abs(42));
    _servoGenouB.write(abs(85));

    _servoHancheC.write(abs(42));
    _servoGenouC.write(abs(85));

    _servoHancheD.write(abs(180 - 42));
    _servoGenouD.write(abs(180 - 85));

    this->hold_shoulders();
}

void PolyDog::move_forward()
{
    int number_of_stages = 7;
    int decalage_A = 0;
    int decalage_B = 4;
    int decalage_C = 0;
    int decalage_D = 4;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        Serial.println("jambe A");
        this->forward_leg(1, (stage + decalage_A) % number_of_stages, 180, 180);
        Serial.println("jambe B");
        this->forward_leg(2, (stage + decalage_B) % number_of_stages, 0, 0);
        Serial.println("jambe C");
        this->forward_leg(3, (stage + decalage_C) % number_of_stages, 0, 0);
        Serial.println("jambe D");
        this->forward_leg(4, (stage + decalage_D) % number_of_stages, 180, 180);
        Serial.println("-------------");

        delay(100);
    }
}
