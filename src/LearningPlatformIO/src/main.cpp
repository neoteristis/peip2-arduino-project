#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>
#include <PolyDog.h>

int val_hanche;
int val_genou;

Servo servo;

PolyDog dog;

CustomServos servo01(7);
CustomServos servo02(6);

void setup()
{
    // dog.attach_all_motors();
    // dog.start();
    Serial.begin(9600);
    // servo.attach(35);

    servo01.attach();
    servo02.attach();
}

void loop()
{
    // dog.hold_shoulders();
    // dog.move_forward();
    dog.forward_leg(servo01, servo02, 180, 180);
    /*     servo.write(90);
        delay(300);
        servo.write(40);
        delay(300); */
}
