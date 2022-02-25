/*
  CustomServos.cpp - Library to use servos with custom functions
  Created by Raphaël Anjou, Januray 29, 2022
  Released into the public domain.
*/

#include <Arduino.h>
#include "CustomServos/CustomServos.h"
#include "PolyDog.h"

PolyDog::PolyDog() : _servoEpauleA(8),  // Epaule A
                     _servoHancheA(9), // Hanche A
                     _servoGenouA(10),  // Genou A
                     _servoEpauleB(24), // Epaule B
                     _servoHancheB(25), // Hanche B
                     _servoGenouB(26),  // Genou B
                     _servoEpauleC(23), // Epaule C
                     _servoHancheC(22), // Hanche C
                     _servoGenouC(21),  // Genou C
                     _servoEpauleD(7),  // Epaule D
                     _servoHancheD(6),  // Hanche D
                     _servoGenouD(5)    // Genou D

{
    // HOLDER
}

void PolyDog::forward_leg(int leg_number, int step)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;

    // The arrangement of the legs means that the direction of rotation of the servo motors changes
    int offset_genou;
    int offset_hanche;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 0;
        offset_hanche = 0;
    }

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen
    switch (step)
    {
    default:
    case 1:
        servo_hanche.write(abs(offset_hanche - 50));
        servo_genou.write(abs(offset_genou - 98));
        break;
    case 2:
        servo_genou.write(abs(offset_genou - 63));
        break;
    case 3:
        servo_hanche.write(abs(offset_hanche - 67));
        break;
    case 4:
        servo_genou.write(abs(offset_genou - 66));
        break;
    case 5:
        servo_genou.write(abs(offset_genou - 83));
        break;
    case 6:
        servo_genou.write(abs(offset_genou - 98));
        break;
    case 7:
        servo_hanche.write(abs(offset_hanche - 50));
    }
}

void PolyDog::move_forward()
{
    int number_of_stages = 8;
    int decalage_A = 0;
    int decalage_B = 4;
    int decalage_C = 0;
    int decalage_D = 4;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        delay(100);
    }
}

void PolyDog::forward_leg2(int leg_number, int step)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;

    int offset_genou;
    int offset_hanche;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 0;
        offset_hanche = 0;
    }

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen
    switch (step)
    {
    default:
    case 1:
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        break;

    case 2:
        servo_hanche.write(abs(offset_hanche - 55));
        servo_genou.write(abs(offset_genou - 45));

    case 3:
        servo_hanche.write(abs(offset_hanche - 90));
        servo_genou.write(abs(offset_genou - 50));
    
    case 4:
        servo_hanche.write(abs(offset_hanche - 100));
        servo_genou.write(abs(offset_genou - 85));
    }
}

void PolyDog::move_forward2()
{
    int number_of_stages = 16;
    int decalage_A = 0;
    int decalage_B = 4;
    int decalage_C = 8;
    int decalage_D = 12;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        delay(300);
    }
}

void PolyDog::hold_shoulders()
{
    _servoEpauleA.write(42);
    _servoEpauleB.write(74);
    _servoEpauleC.write(154);
    _servoEpauleD.write(91);
}

void PolyDog::start()
{
    int ANGLE_HANCHE = 70;
    int ANGLE_GENOU = 70;
    int OFFSET = 165;
    // Start position
    _servoHancheA.write(abs(OFFSET - ANGLE_HANCHE));
    _servoGenouA.write(abs(OFFSET - ANGLE_GENOU));

    _servoHancheB.write(abs(ANGLE_HANCHE));
    _servoGenouB.write(abs(ANGLE_GENOU));

    _servoHancheC.write(abs(ANGLE_HANCHE));
    _servoGenouC.write(abs(ANGLE_GENOU));

    _servoHancheD.write(abs(OFFSET - ANGLE_HANCHE));
    _servoGenouD.write(abs(OFFSET - ANGLE_GENOU));

    this->hold_shoulders();
}

void PolyDog::position_attente()
{
    int ANGLE_HANCHE = 80;
    int ANGLE_GENOU = 80;
    int OFFSET = 170;
    // Start position
    _servoHancheA.write(abs(OFFSET - ANGLE_HANCHE));
    _servoGenouA.write(abs(OFFSET - ANGLE_GENOU));

    _servoHancheB.write(abs(ANGLE_HANCHE));
    _servoGenouB.write(abs(ANGLE_GENOU));

    _servoHancheC.write(abs(ANGLE_HANCHE));
    _servoGenouC.write(abs(ANGLE_GENOU));

    _servoHancheD.write(abs(OFFSET - ANGLE_HANCHE));
    _servoGenouD.write(abs(OFFSET - ANGLE_GENOU));

    delay(500);
    ANGLE_HANCHE = 70;
    ANGLE_GENOU = 70;

    _servoHancheA.write(abs(OFFSET - ANGLE_HANCHE));
    _servoGenouA.write(abs(OFFSET - ANGLE_GENOU));

    _servoHancheB.write(abs(ANGLE_HANCHE));
    _servoGenouB.write(abs(ANGLE_GENOU));

    delay(1000);


    this->hold_shoulders();
}

void PolyDog::move_aside_leg(int leg_number, int step)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;
    CustomServos servo_epaule;

    int offset_genou;
    int offset_hanche;
    int angleconverter;
    int offset_epaule;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        servo_epaule = _servoEpauleA;
        offset_genou = 170;
        offset_hanche = 170;
        offset_epaule = 42;
        angleconverter = 0;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        servo_epaule = _servoEpauleB;
        offset_genou = 0;
        offset_hanche = 0;
        offset_epaule = 74;
        angleconverter = 0;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        servo_epaule = _servoEpauleC;
        offset_genou = 0;
        offset_hanche = 0;
        offset_epaule = 154;
        angleconverter = -85;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        servo_epaule = _servoEpauleD;
        offset_genou = 170;
        offset_hanche = 170;
        offset_epaule = 91;
        angleconverter = 180;
        break;
    }

    if (step==1){
        delay(500);
        servo_hanche.write(abs(offset_hanche - 70));
        servo_genou.write(abs(offset_genou - 70));
        delay(500);
        servo_hanche.write(abs(offset_hanche - 55));
        servo_genou.write(abs(offset_genou - 45));
        delay(500);
        servo_epaule.write(abs(-angleconverter + offset_epaule -20));
        delay(500);
        servo_hanche.write(abs(offset_hanche - 80));
        servo_genou.write(abs(offset_genou - 85));
        delay(500);
    }
    else if (step==2){
        if (leg_number==1 or leg_number==4){
         servo_epaule.write(abs(-angleconverter + offset_epaule));
        }

        if (leg_number==2 or leg_number==3){
         servo_epaule.write(abs(-angleconverter + offset_epaule -20));
        }
    }

    else{
        if (leg_number==1 or leg_number==4){
            servo_epaule.write(abs(-angleconverter + offset_epaule +40));
            }

        if (leg_number==2 or leg_number==3){
            servo_epaule.write(abs(-angleconverter + offset_epaule));
            }
    }

}

void PolyDog::move_aside()
{
    
    move_aside_leg(1,1);
    delay(100);
    move_aside_leg(4,1);
    delay(500);
    move_aside_leg(4,2);
    move_aside_leg(1,2);
    move_aside_leg(3,2);
    move_aside_leg(2,2);
    delay(100);
    move_aside_leg(2,1);
    delay(100);
    move_aside_leg(3,1);
    delay(500);
    delay(200);
    

}

void PolyDog::avancer_jambe_test(int leg_number){

    CustomServos servo_hanche;
    CustomServos servo_genou;

    int offset_genou;
    int offset_hanche;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    case 2: // LEG B
        servo_hanche = _servoHancheB;
        servo_genou = _servoGenouB;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 3: // LEG C
        servo_hanche = _servoHancheC;
        servo_genou = _servoGenouC;
        offset_genou = 0;
        offset_hanche = 0;
        break;
    case 4: // LEG D
        servo_hanche = _servoHancheD;
        servo_genou = _servoGenouD;
        offset_genou = 170;
        offset_hanche = 170;
        break;
    default:
        servo_hanche = _servoHancheA;
        servo_genou = _servoGenouA;
        offset_genou = 0;
        offset_hanche = 0;
    }

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chose
        delay(1000);
        servo_hanche.write(abs(offset_hanche - 42));
        servo_genou.write(abs(offset_genou - 85));
        delay(1000);
        servo_hanche.write(abs(offset_hanche - 55));
        servo_genou.write(abs(offset_genou - 45));
        delay(1000);
        servo_hanche.write(abs(offset_hanche - 90));
        servo_genou.write(abs(offset_genou - 50));
        delay(1000);
        servo_hanche.write(abs(offset_hanche - 100));
        servo_genou.write(abs(offset_genou - 85));
        // servo_genou.write(abs(offset_genou - 95));
        // delay(1000);
        // servo_hanche.write(abs(offset_hanche - 42));

}

void PolyDog::avancer_test()
{
    avancer_jambe_test(1);
    // avancer_jambe_test(2);
    // avancer_jambe_test(3);
    // avancer_jambe_test(4);
    delay(1000);
}






