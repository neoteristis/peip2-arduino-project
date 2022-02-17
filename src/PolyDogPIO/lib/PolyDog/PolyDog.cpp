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

void PolyDog::forward_leg(int leg_number, int current_step)
{

    CustomServos servo_hanche;
    CustomServos servo_genou;

    int offset_genou;
    int offset_hanche;

    // Selection of the leg concerned
    CustomServos *array_servo_chosen = select_leg(leg_number);

    servo_hanche = array_servo_chosen[0];
    servo_genou = array_servo_chosen[1];

    // Selection of the stage of the movement to do
    // All values in the following commands were arbitraty chosen

    // ------- Very small steps but working ------- //
    /* switch (step)
    {
    case 1:
        servo_hanche.write(abs(offset_hanche - 21));
        servo_genou.write(abs(offset_genou - 83));
        break;
    case 2:
        servo_genou.write(abs(offset_genou - 59));
        break;
    case 3:
        servo_hanche.write(abs(offset_hanche - 38));
        break;
    case 4:
        servo_genou.write(abs(offset_genou - 66));
        break;
    case 5:
        servo_hanche.write(abs(offset_hanche - 38));
        break;
    case 6:
        servo_genou.write(abs(offset_genou - 79));
        break;
    case 7:
        servo_hanche.write(abs(offset_hanche - 32));
        break;
    case 8:
        servo_genou.write(abs(offset_genou - 83));
        break;
    case 9:
        servo_hanche.write(abs(offset_hanche - 32));
        break;
    default:
        servo_hanche.write(abs(offset_hanche - 21));
        servo_genou.write(abs(offset_genou - 83));
        break;
    } */

    switch (current_step)
    {
    case 1:
        servo_hanche.write(abs(offset_hanche - 20));
        servo_genou.write(abs(offset_genou - 98));
        break;
    case 2:
        servo_genou.write(abs(offset_genou - 63));
        break;
    case 3:
        servo_hanche.write(abs(offset_hanche - 37));
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
        servo_hanche.write(abs(offset_hanche - 20));
    default:
        servo_hanche.write(abs(offset_hanche - 20));
        servo_genou.write(abs(offset_genou - 98));
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

void PolyDog::attach_one_leg(int leg_number)
{
    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        _servoHancheA.attach();
        _servoGenouA.attach();
        break;
    case 2: // LEG B
        _servoHancheB.attach();
        _servoGenouB.attach();
        break;
    case 3: // LEG C
        _servoHancheC.attach();
        _servoGenouC.attach();
        break;
    case 4: // LEG D
        _servoHancheD.attach();
        _servoGenouD.attach();
        break;
    default:
        _servoHancheA.attach();
        _servoGenouA.attach();
    }
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
    int number_of_stages = 16;
    int decalage_A = 0;
    int decalage_B = 8;
    int decalage_C = 4;
    int decalage_D = 12;

    for (int stage = 1; stage < number_of_stages + 1; stage++)
    {
        this->forward_leg(1, (stage + decalage_A) % number_of_stages);
        this->forward_leg(2, (stage + decalage_B) % number_of_stages);
        this->forward_leg(3, (stage + decalage_C) % number_of_stages);
        this->forward_leg(4, (stage + decalage_D) % number_of_stages);

        delay(200);
    }
}

void PolyDog::control_leg_with_potentio(int leg_number, int pin_potentio01, int pin_potentio02)
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

    servo_hanche.control_two_with_potentio(servo_genou, pin_potentio01, pin_potentio02);
}

CustomServos *PolyDog::select_leg(int leg_number)
{
    CustomServos *servos_array[3];

    CustomServos servo_hip;
    CustomServos servo_knee;
    CustomServos servo_shoulder;

    // Selection of the leg concerned
    switch (leg_number)
    {
    case 1: // LEG A
        servo_hip = _servoHancheA;
        servo_knee = _servoGenouA;
        servo_shoulder = _servoEpauleA;
        break;
    case 2: // LEG B
        servo_hip = _servoHancheB;
        servo_knee = _servoGenouB;
        servo_shoulder = _servoEpauleB;
        break;
    case 3: // LEG C
        servo_hip = _servoHancheC;
        servo_knee = _servoGenouC;
        servo_shoulder = _servoEpauleC;
        break;
    case 4: // LEG D
        servo_hip = _servoHancheD;
        servo_knee = _servoGenouD;
        servo_shoulder = _servoEpauleD;
        break;
    default:
        servo_hip = _servoHancheA;
        servo_knee = _servoGenouA;
        servo_shoulder = _servoEpauleA;
    }

    *servos_array[0] = servo_hip;
    *servos_array[1] = servo_knee;
    *servos_array[2] = servo_shoulder;

    return *servos_array;
}
