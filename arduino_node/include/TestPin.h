#include <Arduino.h>

#define PIN_13 5

void initLED() {
    pinMode(PIN_13, OUTPUT);
}

void openLED() {
    digitalWrite(PIN_13, HIGH);
}

void closeLED() {
    digitalWrite(PIN_13, LOW);
}