#include <Servo.h>

Servo servo_genou;  // create servo object to control a servo
Servo servo_hanche;

int genou = 19;  // analog pin used to connect the potentiometer
int hanche = 17;
int val_genou;    // variable to read the value from the analog pin
int val_hanche;

void setup() {
  servo_genou.attach(9);  // attaches the servo on pin 9 to the servo object
  servo_hanche.attach(7);
  Serial.begin(9600);
}

void loop() {
  val_genou = analogRead(genou);            // reads the value of the potentiometer (value between 0 and 1023)
  val_genou = map(val_genou, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print("val genou : ");
  Serial.print(val_genou);
  Serial.print("\n");
  servo_genou.write(val_genou);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there

  val_hanche = analogRead(hanche);            // reads the value of the potentiometer (value between 0 and 1023)
  val_hanche = map(val_hanche, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  Serial.print("val hanche : ");
  Serial.print(val_hanche);
  Serial.print("\n");
  servo_hanche.write(val_hanche);                  // sets the servo position according to the scaled value
  delay(15);

  Serial.print("------------------------------");
  Serial.print("\n");
}
