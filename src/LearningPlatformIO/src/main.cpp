#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>
#include <PolyDog.h>

int val_hanche;
int val_genou;

PolyDog dog(1);

CustomServos epauleA(36, "epauleA");
CustomServos hancheA(35, "hancheA");
CustomServos genouA(34, "genouA");

CustomServos epauleB(32, "epauleB");
CustomServos hancheB(31, "hancheB");
CustomServos genouB(30, "genouB");

CustomServos epauleC(2, "epauleC");
CustomServos hancheC(3, "hancheC");
CustomServos genouC(4, "genouC");

CustomServos epauleD(8, "epauleD");
CustomServos hancheD(7, "hancheD");
CustomServos genouD(6, "genouD");

void setup()
{
    epauleA.attach();
    hancheA.attach();
    genouA.attach();
    epauleB.attach();
    hancheB.attach();
    genouB.attach();
    epauleC.attach();
    hancheC.attach();
    genouC.attach();
    epauleD.attach();
    hancheD.attach();
    genouD.attach();

    Serial.begin(9600);
}

void loop()
{

    dog.hold_shoulders(epauleA, epauleB, epauleC, epauleD);

    Serial.println("jambe A");
    dog.forward_leg(hancheA, genouA, 180, 180); // LEG A
    Serial.println("jambe B");
    dog.forward_leg(hancheB, genouB, 0, 0); // LEG B
    Serial.println("jambe D");
    dog.forward_leg(hancheD, genouD, 180, 180); // LEG D
    Serial.println("jambe C");
    dog.forward_leg(hancheC, genouC, 0, 0); // LEG C
    Serial.println("FINI");
}
