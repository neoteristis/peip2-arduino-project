/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include <CustomServos.h>
#include <PolyDog.h>

PolyDog::PolyDog()
{
    CustomServos _servoEpauleA(36, "epauleA");
    CustomServos _servoHancheA(35, "hancheA");
    CustomServos _servoGenouA(34, "genouA");

    CustomServos _servoEpauleB(32, "epauleB");
    CustomServos _servoHancheB(31, "hancheB");
    CustomServos _servoGenouB(30, "genouB");

    CustomServos _servoEpauleC(2, "epauleC");
    CustomServos _servoHancheC(3, "hancheC");
    CustomServos _servoGenouC(4, "genouC");

    CustomServos _servoEpauleD(8, "epauleD");
    CustomServos _servoHancheD(7, "hancheD");
    CustomServos _servoGenouD(6, "genouD");
}

void PolyDog::forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int offset_hanche, int offset_genou)
{
    int delay_time = 300;

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));

    // Lift leg
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 30));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 85));

    // Start the knee to go down
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 45));

    // Start position again
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 77));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 38));

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));
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
    this->_servoEpauleA.attach();
    this->_servoHancheA.attach();
    this->_servoGenouA.attach();
    this->_servoEpauleB.attach();
    this->_servoHancheB.attach();
    this->_servoGenouB.attach();
    this->_servoEpauleC.attach();
    this->_servoHancheC.attach();
    this->_servoGenouC.attach();
    this->_servoEpauleD.attach();
    this->_servoHancheD.attach();
    this->_servoGenouD.attach();
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
    this->forward_leg(this->_servoHancheA, this->_servoGenouA, 180, 180); // LEG A
    Serial.println("jambe B");
    this->forward_leg(this->_servoHancheB, this->_servoGenouB, 0, 0); // LEG B
    Serial.println("jambe C");
    this->forward_leg(this->_servoHancheC, this->_servoGenouC, 0, 0); // LEG C
    Serial.println("jambe D");
    this->forward_leg(this->_servoHancheD, this->_servoGenouD, 180, 180); // LEG D
    Serial.println("-------------");
}
