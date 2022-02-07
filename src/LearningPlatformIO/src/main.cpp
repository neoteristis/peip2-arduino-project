#include <Arduino.h>
#include <Servo.h>
#include <CustomServos.h>


int val_hanche;
int val_genou;

Servo servo;

 CustomServos hancheA(35, "hancheA");
 CustomServos genouA(34, "genouA");
 
 CustomServos hancheB(31, "hancheB");
 CustomServos genouB(30, "genouB");
 
 CustomServos hancheC(3, "hancheC");
 CustomServos genouC(4, "genouC");
 
 CustomServos hancheD(7, "hancheD");
 CustomServos genouD(6, "genouD");
 
 CustomServos epauleA(36, "epauleA");
 CustomServos epauleB(32, "epauleB");
 CustomServos epauleC(2, "epauleC");
 CustomServos epauleD(8, "epauleD");

void forward_leg(CustomServos servo_hanche, CustomServos servo_genou, int offset_hanche, int offset_genou)
{
    int delay_time = 300;

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));

    // Lift leg
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 30));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 85));

    // Start the knee to go down
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 45));

    // Start position again
    delay(delay_time);
    servo_genou.write(abs(offset_genou - 77));

    // Go forward
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 38));

    // Start position
    delay(delay_time);
    servo_hanche.write(abs(offset_hanche - 42));
    servo_genou.write(abs(offset_genou - 85));
}

void hold_shoulders(CustomServos shoulderA, CustomServos shoulderB, CustomServos shoulderC, CustomServos shoulderD)
{
    shoulderA.write(48);
    shoulderB.write(79);
    shoulderC.write(158);
    shoulderD.write(89);
}

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

    hold_shoulders(epauleA, epauleB, epauleC, epauleD);

    Serial.println("jambe A");
    forward_leg(hancheA, genouA, 180, 180); // LEG A
    Serial.println("jambe B");
    forward_leg(hancheB, genouB, 0, 0); // LEG B
    Serial.println("jambe D");
    forward_leg(hancheD, genouD, 180, 180); // LEG D
    Serial.println("jambe C");
    forward_leg(hancheC, genouC, 0, 0); // LEG C
    Serial.println("FINI");

}
