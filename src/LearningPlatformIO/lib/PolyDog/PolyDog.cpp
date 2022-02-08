/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include <CustomServos.h>
#include <PolyDog.h>

PolyDog::PolyDog() : _servoEpauleA(36, "epauleA"),
                     _servoHancheA(35, "hancheA"),
                     _servoGenouA(34, "genouA"),
                     _servoEpauleB(32, "epauleB"),
                     _servoHancheB(31, "hancheB"),
                     _servoGenouB(30, "genouB"),
                     _servoEpauleC(2, "epauleC"),
                     _servoHancheC(3, "hancheC"),
                     _servoGenouC(4, "genouC"),
                     _servoEpauleD(8, "epauleD"),
                     _servoHancheD(7, "hancheD"),
                     _servoGenouD(6, "genouD")

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
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
    }

    // Selection of the part of the movement to do
    switch (step)
    {
    case 1:
        // Start position
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;

    case 2:
        // Lift leg
        servo_genou.write(abs(offset_genou - 30));
        break;

    case 3:
        // Go forward
        servo_hanche.write(abs(offset_hanche - 85));
        break;

    case 4:
        // Go forward
        servo_hanche.write(abs(offset_hanche - 85));
        break;

    case 5:
        // Start position again
        servo_genou.write(abs(offset_genou - 77));
        break;

    case 6:
        // Go forward
        servo_hanche.write(abs(offset_hanche - 38));
        break;

    case 7:
        // Start position
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;

    default:
        // Start position
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
    // this->_servoHancheA.attach();
    // this->_servoGenouA.attach();
    _servoEpauleB.attach();
    // this->_servoHancheB.attach();
    // this->_servoGenouB.attach();
    _servoEpauleC.attach();
    // this->_servoHancheC.attach();
    // this->_servoGenouC.attach();
    _servoEpauleD.attach();
    // this->_servoHancheD.attach();
    // this->_servoGenouD.attach();
}

void PolyDog::start()
{
    int delay_time = 300;
    // Start position
    delay(delay_time);
    this->_servoHancheA.write(abs(180 - 42));
    this->_servoGenouA.write(abs(180 - 85));

    delay(delay_time);
    this->_servoHancheB.write(abs(42));
    this->_servoGenouB.write(abs(85));

    delay(delay_time);
    this->_servoHancheC.write(abs(42));
    this->_servoGenouC.write(abs(85));

    delay(delay_time);
    this->_servoHancheD.write(abs(180 - 42));
    this->_servoGenouD.write(abs(180 - 85));
}

void PolyDog::move_forward()
{
    Serial.println("jambe A");
    this->forward_leg(1, 0, 180, 180); // LEG A
    Serial.println("jambe B");
    this->forward_leg(2, 0, 0, 0); // LEG B
    Serial.println("jambe C");
    this->forward_leg(3, 0, 0, 0); // LEG C
    Serial.println("jambe D");
    this->forward_leg(4, 0, 180, 180); // LEG D
    Serial.println("-------------");
}
