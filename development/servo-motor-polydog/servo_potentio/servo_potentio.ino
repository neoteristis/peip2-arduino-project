#include <Servo.h>

int val_genou;    // variable to read the value from the analog pin
int val_hanche;

int pin_genou = 7;
int pin_hanche = 9;

int pot_genou = 13;
int pot_hanche = 14;

Servo servo_hanche;
Servo servo_genou;

void setup() {
  Serial.begin(9600);
  Serial.println("---- Scaling program ----");

  servo_genou.attach(pin_genou);
  servo_hanche.attach(pin_hanche);
}

void loop() {
  val_genou = analogRead(pot_genou);            // reads the value of the potentiometer (value between 0 and 1023)
  servo_genou.write(map(val_genou, 0, 1023, 0, 179));
  delay(15);                           // waits for the servo to get there

  val_hanche = analogRead(pot_hanche);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("val hanche : ");
  Serial.print(val_hanche);
  Serial.print("| val genou : ");
  Serial.print(val_genou);
  Serial.print("\n");
  servo_hanche.write(map(val_hanche, 0, 1023, 0, 179));
  delay(15);
}
