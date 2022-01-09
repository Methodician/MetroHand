#include <Arduino.h>
// #define EI_ARDUINO_INTERRUPTED_PIN
// #include <EnableInterrupt.h>

// 12 pins declared with finger-number naming convention
// e.g. i1, i2, i3, m1, m2, m3, r1, r2, r3, p1, p2, p3
const uint8_t PI1 = 2, PI2 = 3, PI3 = 4, PM1 = 5, PM2 = 6, PM3 = 7, PR1 = 8, PR2 = 9, PR3 = 10, PP1 = 11, PP2 = 12, PP3 = 19;
const uint8_t NUMBER_OF_FINGER_PINS = 12;
const uint8_t FINGER_PINS [NUMBER_OF_FINGER_PINS] = {PI1, PI2, PI3, PM1, PM2, PM3, PR1, PR2, PR3, PP1, PP2, PP3};

const uint8_t NUMBER_OF_CHARS = 13;

const uint16_t ka = 0b111111111110;
const uint16_t kb = 0b111111111101;
const uint16_t kc = 0b111111111011;
const uint16_t kd = 0b111111110111;
const uint16_t ke = 0b111111101111;
const uint16_t kf = 0b111111011111;
const uint16_t kg = 0b111110111111;
const uint16_t kh = 0b111101111111;
const uint16_t ki = 0b111011111111;
const uint16_t kj = 0b110111111111;
const uint16_t kk = 0b101111111111;
const uint16_t kl = 0b011111111111;
const uint16_t km = 0b111111110110;

const uint16_t keyStates [NUMBER_OF_CHARS] = {ka, kb, kc, kd, ke, kf, kg, kh, ki, kj, kk, kl, km};
const char possibleChars [NUMBER_OF_CHARS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
// volatile bool comboState [NUMBER_OF_FINGER_PINS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// volatile uint32_t lastKeyoutMs = 0;
// volatile uint32_t lastInterruptMs [NUMBER_OF_FINGER_PINS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// void updateLastInterruptMs (uint8_t fingerPin, uint32_t interruptMs) {
//   lastInterruptMs [fingerPin] = interruptMs;
// }

int matchIndex (uint16_t testState) {
  int index = -1;
  for (int i = 0; i < NUMBER_OF_CHARS; i++) {
    if (keyStates[i] == testState) {
      index = i;
      break;
    }
  }
  return index;
}

void setup() {
  for (uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
    pinMode(FINGER_PINS[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop() {
  uint16_t result = 0;
  for (uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
    bitWrite(result, i, digitalRead(FINGER_PINS[i]));
  }

  const int charIndex = matchIndex(result);
  if (charIndex >= 0) {
    Serial.print(possibleChars[charIndex]);
  }
  delay(250);
}

// EXPERIMENTING WITH BIT MASKS OF ENTIRE PORTS
// #include <Arduino.h>
// #define EI_ARDUINO_INTERRUPTED_PIN
// #include <EnableInterrupt.h>

// const uint8_t PI1 = 2, PI2 = 3, PI3 = 4, PM1 = 5, PM2 = 6, PM3 = 7, PR1 = 8, PR2 = 9, PR3 = 10, PP1 = 11, PP2 = 12, PP3 = 19;
// const uint8_t NUMBER_OF_FINGER_PINS = 12;
// const uint8_t FINGER_PINS [12] = {PI1, PI2, PI3, PM1, PM2, PM3, PR1, PR2, PR3, PP1, PP2, PP3};



// void setup() {
//   for (uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
//     pinMode(FINGER_PINS[i], INPUT_PULLUP);
//   }

//   Serial.begin(9600);

//   Serial.print("0xAA ");
//   Serial.println(0xAA);

//   Serial.print("0x55 ");
//   Serial.println(0x55);

//   Serial.print("0xBB ");
//   Serial.println(0xBB);
// }

// void loop() {

//   Serial.print("PINB ");
//   Serial.print(PINB, BIN);
//   Serial.print(" - PINC ");
//   Serial.print(PINC, BIN);
//   Serial.print(" - PIND ");
//   Serial.println(PIND, BIN);
//   delay(200);
// }


// USING ARDUINO INTERRUPT LIBRARY
// #include <Arduino.h>
// #define EI_ARDUINO_INTERRUPTED_PIN
// #include <EnableInterrupt.h>

// const uint8_t PI1 = 2, PI2 = 3, PI3 = 4, PM1 = 5, PM2 = 6, PM3 = 7, PR1 = 8, PR2 = 9, PR3 = 10, PP1 = 11, PP2 = 12, PP3 = 19;
// const uint8_t NUMBER_OF_FINGER_PINS = 12;
// const uint8_t FINGER_PINS [12] = {PI1, PI2, PI3, PM1, PM2, PM3, PR1, PR2, PR3, PP1, PP2, PP3};



// void isr() {
//   Serial.println("ISR");
//   Serial.println(arduinoInterruptedPin);
//   Serial.println(arduinoPinState);
// }

// void setup() {
//   for (uint8_t i = 0; i < NUMBER_OF_FINGER_PINS; i++) {
//     pinMode(FINGER_PINS[i], INPUT_PULLUP);
//     enableInterrupt(FINGER_PINS[i], isr, CHANGE);
//   }

//   Serial.begin(9600);
// }

// void loop() {
//   Serial.println("delays");
//   delay(1000);
// }