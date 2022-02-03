#include <Arduino.h>
#include <Servo.h>

int val1;
int val2;

Servo hanche;
Servo genou;

void setup()
{
    hanche.attach(3);
    genou.attach(2);
}

void loop()
{
    val1 = map(analogRead(1), 0, 1023, 0, 180);
    val2 = map(analogRead(2), 0, 1023, 0, 180);

    hanche.write(val1);
    genou.write(val2);
}