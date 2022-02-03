// #include <CustomServos.h>
#include <Arduino.h>
#include <Servo.h>

Servo servo01;

// CustomServos servo01(7, 0, 180);
// CustomServos servo02(3, 0, 180);
// CustomServos servo03(4, 0, 180);
// CustomServos servo04(5, 0, 180);
// CustomServos servo05(6, 0, 180);
// CustomServos servo06(7, 0, 180);
// CustomServos servo07(8, 0, 180);
// CustomServos servo08(9, 0, 180);
// CustomServos servo09(10, 0, 180);
// CustomServos servo10(11, 0, 180);
// CustomServos servo11(12, 0, 180);
// CustomServos servo12(13, 0, 180);

void setup()
{
    Serial.begin(9600);
    servo01.attach(2);
}

void loop()
{
    Serial.println("yoooooo");
    // servo01.write_angle(25);
    servo01.write(25);
    delay(1000);
    servo01.write(100);
    // servo01.write_angle(100);
    delay(1000);
    // servo02.write_angle(25);
    // servo03.write_angle(134);
    // servo04.write_angle(90);
    // servo05.write_angle(25);
    // servo06.write_angle(25);
    // servo07.write_angle(155);
    // servo08.write_angle(155);
    // servo09.write_angle(46);
    // servo10.write_angle(70);
    // servo11.write_angle(155);
    // servo12.write_angle(155);
}