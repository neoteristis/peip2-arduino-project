#include <Servo.h>
Servo servo1;

void setup() {

 servo1.attach(9);
 servo1.write(180);
 delay(2000);
 servo1.write(90);

}

void loop(){

}
