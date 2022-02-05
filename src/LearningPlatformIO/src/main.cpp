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
    // servo07.attach();
    // servo08.attach();
    // servo09.attach();
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
    // End of calculated for C leg

    Serial.print("hanche: ");
    Serial.print(angle_hanche);
    Serial.print("     genou: ");
    Serial.print(angle_genou);
    Serial.print("     height: ");
    Serial.println(b);

    // servo03.write(angle_genou);                       //genou A
    // servo02.write(angle_hanche);                      //hanche A
    // servo01.write(41);                                //epaule A -> value to be at 90 from ground
    // servo06.write(76);                                //epaule B -> value to be at 90 from ground
    // servo05.write(map(angle_hanche, 0, 180, 180, 0)); //hanche B
    // servo04.write(angle_genou);  //genou B
    // servo09.write(angle_genou);  //genou C
    // servo08.write(map(angle_hanche, 0, 180, 180, 0)); //hanche C
    // servo07.write(158);                               //epaule C -> value to be at 90 from ground
    servo12.write(92);                                //epaule D -> value to be at 90 from ground
    servo11.write(angle_hanche);                      //hanche D
    servo10.write(angle_genou);                       //genou D
}