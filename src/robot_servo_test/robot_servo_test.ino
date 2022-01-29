#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

Adafruit_PWMServoDriver pwm_genou = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_hanche = Adafruit_PWMServoDriver();

int val_genou; // variable to read the value from the analog pin
int val_hanche;

uint8_t pin_genou = 0;
uint8_t pin_hanche = 1;

int genou = 13;
int hanche = 14;

void setup()
{
  Serial.begin(9600);
  Serial.println("---- Scaling program ----");

  pwm_genou.begin();
  pwm_hanche.begin();

  pwm_genou.setPWMFreq(50);
  pwm_hanche.setPWMFreq(50);
}

void loop()
{
  val_genou = analogRead(genou); // reads the value of the potentiometer (value between 0 and 1023)
  pwm_genou.setPWM(pin_genou, 0, val_genou);
  // pwm_genou.setPWM(pin_genou, 0, 700);
  delay(15); // waits for the servo to get there

  val_hanche = analogRead(hanche); // reads the value of the potentiometer (value between 0 and 1023)
  Serial.print("val hanche : ");
  Serial.print(val_hanche);
  Serial.print("| val genou : ");
  Serial.print(val_genou);
  Serial.print("\n");
  pwm_hanche.setPWM(pin_hanche, 0, val_hanche);
  // pwm_hanche.setPWM(pin_hanche, 0, 700);
  delay(15);
}
