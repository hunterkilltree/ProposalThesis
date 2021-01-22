#include <Arduino.h>
#include <./TestPin.h>
// #include 

void setup() {
  // put your setup code here, to run once:
  openLED();
}

void loop() {
  // put your main code here, to run repeatedly:
  openLED();

  delay(2000);

  closeLED();

  delay(2000);
}