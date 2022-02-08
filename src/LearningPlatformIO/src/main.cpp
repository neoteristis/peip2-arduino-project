#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>
#include <PolyDog.h>

// CustomServos servo(2);

PolyDog dog = PolyDog();

// CustomServos servo01(7);
// CustomServos servo02(6);

// CustomServos servo03(34);
// CustomServos servo04(35);

// CustomServos servo05(30);
// CustomServos servo06(31);

// CustomServos servo07(3);
// CustomServos servo08(4);

void forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int step, int offset_hanche, int offset_genou)
{

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

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    dog.attach_all_motors();
    // dog.start();
    Serial.begin(9600);
    // servo.attach();
    // servo01.attach();
    // servo02.attach();
    // servo03.attach();
    // servo04.attach();
    // servo05.attach();
    // servo06.attach();
    // servo07.attach();
    // servo08.attach();
}

void loop()
{
    // MAIN LOOP
    dog.hold_shoulders();
}
