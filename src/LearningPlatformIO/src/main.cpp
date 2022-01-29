#include <CustomServos.h>
#include <Arduino.h>
#include <Servo.h>

int servo_pin = 19;
CustomServos servo01(servo_pin, "servo01", 0, 180);
Servo servo;

void setup()
{
    Serial.begin(9600);
    servo.attach(19);
}

void loop()
{
    //servo01.max_rotation();
    servo.write(0);
    delay(1000);
    // servo01.min_rotation();
    servo.write(180);
    delay(1000);

    Serial.write("RUNNING");
}