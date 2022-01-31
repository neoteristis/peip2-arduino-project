#include <Servo.h>

Servo servo_genou;
Servo servo_hanche;

int val_genou;
int val_hanche;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  servo_genou.attach(2);
  servo_hanche.attach(3);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val_genou = analogRead(0);
  val_hanche = analogRead(1);

  Serial.print("Genou : ");
  Serial.print(val_genou);
  Serial.print(" Hanche : ");
  Serial.println(val_hanche);

  servo_genou.write(map(val_genou, 0, 1023, 0, 180));
  delay(15);
  servo_hanche.write(map(val_hanche, 0, 1023, 0, 180));
  delay(15);

}
