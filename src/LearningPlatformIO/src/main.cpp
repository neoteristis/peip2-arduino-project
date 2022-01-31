#include <CustomServos.h>
#include <Arduino.h>
#include <Servo.h>

CustomServos servo01(2, 0, 180);
CustomServos servo02(3, 0, 180);
CustomServos servo03(4, 0, 180);
CustomServos servo04(5, 0, 180);
CustomServos servo05(6, 0, 180);
CustomServos servo06(7, 0, 180);
CustomServos servo07(8, 0, 180);
CustomServos servo08(9, 0, 180);
CustomServos servo09(10, 0, 180);
CustomServos servo10(11, 0, 180);
CustomServos servo11(12, 0, 180);
CustomServos servo12(13, 0, 180);

int val1;
int val2;
int val3;

void setup()
{
    servo01.attach();
    servo02.attach();
    servo03.attach();
    servo04.attach();
    servo05.attach();
    servo06.attach();
    servo07.attach();
    servo08.attach();
    servo09.attach();
    servo10.attach();
    servo11.attach();
    servo12.attach();

    Serial.begin(9600);
}

void loop()
{
    val1 = map(analogRead(1), 0, 1023, 0, 180);
    val2 = map(analogRead(2), 0, 1023, 0, 180);
    val3 = map(analogRead(3), 0, 1023, 0, 180);
    Serial.print(val1);
    Serial.print("   ");
    Serial.print(val2);
    Serial.print("   ");
    Serial.println(val3);

    servo01.write(179);
    servo02.write(35);
    servo03.write(42);
    servo04.write(179);
    servo05.write(89);
    servo06.write(11);
    servo07.write(122);
    servo08.write(0);
    servo09.write(159);
    servo10.write(98);
    servo11.write(166);
    servo12.write(0);
}