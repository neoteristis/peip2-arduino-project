#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;

int val1;
int val2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  servo7.attach(8);
  servo8.attach(9);
  servo9.attach(10);
  servo10.attach(11);
  servo11.attach(12);
  servo12.attach(13);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  val1 = analogRead(0);
  val2 = analogRead(1);

  Serial.print("Val5 : ");
  Serial.print(map(val1, 0, 1023, 0, 180));
  Serial.print(" Val6 : ");
  Serial.println(map(val2, 0, 1023, 0, 180));


  servo1.write(25);
  servo2.write(25);
  servo3.write(134);
  servo4.write(90); 
  servo5.write(25);
  servo6.write(25);
  servo7.write(155);
  servo8.write(155);
  servo9.write(46);
  servo10.write(70);
  servo11.write(155);
  servo12.write(155);
  
  //servo3.write(map(val1, 0, 1023, 0, 180));
  //servo12.write(map(val2, 0, 1023, 0, 180));
  
  
  delay(15);
}
