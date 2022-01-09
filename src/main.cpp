#include <Arduino.h>

// 12 pins declared with finger-number naming convention
// e.g. i1, i2, i3, m1, m2, m3, r1, r2, r3, p1, p2, p3
const uint8_t PI1 = 2, PI2 = 3, PI3 = 4, PM1 = 5, PM2 = 6, PM3 = 7, PR1 = 8, PR2 = 9, PR3 = 10, PP1 = 11, PP2 = 12, PP3 = 19;
const uint8_t NUMBER_OF_FINGER_PINS = 12;
const uint8_t FINGER_PINS [12] = {PI1, PI2, PI3, PM1, PM2, PM3, PR1, PR2, PR3, PP1, PP2, PP3};

volatile bool comboState [NUMBER_OF_FINGER_PINS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

volatile uint32_t lastKeyoutMs = 0;
volatile uint32_t lastInterruptMs [NUMBER_OF_FINGER_PINS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void updateLastInterruptMs (uint8_t fingerPin, uint32_t interruptMs) {
  lastInterruptMs [fingerPin] = interruptMs;
}

void setup() {
  // put your setup code here, to run once:
  for (uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
    pinMode(FINGER_PINS[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for(uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
    Serial.print(digitalRead(FINGER_PINS[i]));
    Serial.print(" ");
  }
  Serial.println();
}