// #include <math.h>
// #include <Arduino.h>
// #include <Servo.h>

// float A;
// float B;
// float C;
// float a = 9.7;
// float b;
// float c = 10;
// Servo servo_hanche;
// Servo servo_genou;

// int angle_genou;
// int angle_hanche;

// float fmap(float x, float a, float b, float c, float d)
// {
//     float f = x / (b - a) * (d - c) + c;
//     return f;
// }

// void setup()
// {
//     Serial.begin(9600);
//     servo_hanche.attach(2);
//     servo_genou.attach(3);
// }

// void loop()
// {
//     b = fmap((float)analogRead(1), 0.0, 1023.0, 10.5, 19.3);

//     B = acos(b / (2 * a)) * 180 / PI;
//     C = 180 - (180 - 2 * B);

//     angle_genou = (90 - (int)C);
//     angle_hanche = (90 - (int)B) * 40 / 25;

//     servo_genou.write(angle_genou);
//     servo_hanche.write(angle_hanche);

//     Serial.print("hanche: ");
//     Serial.print(angle_hanche);
//     Serial.print("     genou: ");
//     Serial.print(angle_genou);
//     Serial.print("     height: ");
//     Serial.println(b);
// }