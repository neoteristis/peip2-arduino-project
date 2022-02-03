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

float A;
float B;
float C;
float a = 9.7;
float b;
float c = 10;

int angle_genou;
int angle_hanche;

int Bint;
int Cint;

float fmap(float x, float a, float b, float c, float d)
{
    float f = x / (b - a) * (d - c) + c;
    return f;
}

void setup()
{
    // servo01.attach();
    // servo02.attach();
    // servo03.attach();
    // servo04.attach();
    // servo05.attach();
    // servo06.attach();
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
    // Calculated for C leg
    b = fmap((float)analogRead(1), 0.0, 1023.0, 10.5, 19.3);

    B = acos(b / (2 * a)) * 180 / PI;
    C = 180 - (180 - 2 * B);

    Cint = (int)C;
    Bint = (int)B;

    angle_genou = (90 - Cint);
    angle_hanche = (90 - Bint) * 40 / 25;
    // End of calcultaed for C leg

    Serial.print("hanche: ");
    Serial.print(angle_hanche);
    Serial.print("     genou: ");
    Serial.print(angle_genou);
    Serial.print("     height: ");
    Serial.println(b);

    servo01.write(angle_genou);                 //genou A
    servo02.write(angle_hanche);                //hanche A
    servo03.write(42);                          //epaule A
    servo04.write(80);                          //epaule B
    servo05.write(angle_hanche);                //hanche B
    servo06.write(angle_genou);                 //genou B
    servo07.write(90 - Cint);                   //genou C
    servo08.write((90 - Bint) * 40 / 25);       //hanche C
    servo09.write(159);                         //epaule C
    servo10.write(98);                          //epaule D
    servo11.write((180 - 90 - Bint) * 40 / 25); //hanche D
    servo12.write(180 - 90 - Cint);             //genou D
}