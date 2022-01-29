#include <Servo.h>

Servo servo_genou;  // create servo object to control a servo
Servo servo_hanche;

int genou = 19;  // analog pin used to connect the potentiometer
int hanche = 17;
int pos;

void setup() {
  servo_genou.attach(9);  // attaches the servo on pin 9 to the servo object
  servo_hanche.attach(7);
}

void loop() {
  
  // Start position
  servo_genou.write(145);                 
  servo_hanche.write(141);                 
  delay(150);


  // ------ start to move forward ------ 
  // Move first the hip
  servo_hanche.write(86);
  delay(150);

  // Move the knee to catch back the hip
  servo_genou.write(170);
  delay(150);

  // Continue the hip movement
  servo_hanche.write(56);
  delay(150);

  // Knee movement
  servo_genou.write(125);
  

  delay(1000);
  
  // ------ start to move backward ------


  servo_genou.write(170);
  delay(150);

  servo_hanche.write(86);
  delay(150);

  servo_genou.write(145);                 
  servo_hanche.write(141);                 
  delay(150);

  delay(1000);

}
