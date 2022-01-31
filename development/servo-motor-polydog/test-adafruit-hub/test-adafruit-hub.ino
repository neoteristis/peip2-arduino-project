#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm_genou = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_hanche = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver pwm_epaule = Adafruit_PWMServoDriver();

#define SERVOMIN 300
#define SERVOMAX 350
#define USMIN 600
#define USMAX 1200
#define SERVO_FREQ 50

uint8_t pin_genou = 0;
uint8_t pin_hanche = 1;
uint8_t pin_epaule = 2;

void setup() {
  Serial.begin(9600);
  Serial.println("---- Testing Adafruit board ----");

  pwm_genou.begin();
  pwm_hanche.begin();
  pwm_epaule.begin();
  // pwm.setOscillatorFrequency(27000000);
  pwm_genou.setPWMFreq(SERVO_FREQ);
  pwm_hanche.setPWMFreq(SERVO_FREQ);
  pwm_epaule.setPWMFreq(SERVO_FREQ);
}

void loop() {

    Serial.println(pin_hanche);
    for (uint16_t pulselen = 300; pulselen < 400; pulselen++) {
      pwm_hanche.setPWM(pin_hanche, 0, pulselen);
    }


    Serial.println(pin_genou);
    for (uint16_t pulselen = 400; pulselen < 1000; pulselen++) {
      pwm_genou.setPWM(pin_genou, 0, pulselen);
    }
  
    for (uint16_t pulselen = 1000; pulselen > 400; pulselen--) {
      pwm_genou.setPWM(pin_genou, 0, pulselen);
    }

    for (uint16_t pulselen = 400; pulselen > 300; pulselen--) {
      pwm_hanche.setPWM(pin_hanche, 0, pulselen);
    }

  delay(500);
  for (uint16_t pulselen = 350; pulselen > 100; pulselen--) {
    pwm_epaule.setPWM(pin_epaule, 0, pulselen);
  }

  delay(500);

  Serial.println(pin_epaule);
  for (uint16_t pulselen = 100; pulselen < 350; pulselen++) {
    pwm_epaule.setPWM(pin_epaule, 0, pulselen);
  }

  delay(500);

}
