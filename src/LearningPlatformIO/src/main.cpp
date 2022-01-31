#include <CustomServos.h>
#include <Arduino.h>

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

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    servo01.write(25);
    servo02.write(25);
    servo03.write(134);
    servo04.write(90);
    servo05.write(25);
    servo06.write(25);
    servo07.write(155);
    servo08.write(155);
    servo09.write(46);
    servo10.write(70);
    servo11.write(155);
    servo12.write(155);
}