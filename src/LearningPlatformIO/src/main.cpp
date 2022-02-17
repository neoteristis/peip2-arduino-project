#include <Arduino.h>
//#include <PolyDog.h>


// PolyDog dog = PolyDog();

// void setup()
// {
//     Serial.begin(9600);
//     Serial.println("#5 P2000");
//     dog.start();
//     Serial.println("oui");

// }

// void loop()
// {
//     dog.move_forward();
//     Serial.println("ok");
    
// }
void move(int servo, int position, int time) {
   Serial.print("#");
   Serial.print(servo);
   Serial.print("P");
   Serial.print(position);
   Serial.print(" T");
   Serial.println(time);
   delay(time);
}

void setup() {
   Serial.begin(9600);
   Serial.println("er");
}

void loop() {
    Serial.println("yo");
   move(6, 2000, 1000);
   move(6, 1000, 1000);
}

