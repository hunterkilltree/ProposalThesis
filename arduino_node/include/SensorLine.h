#include <Arduino.h>

const int pinA5 = A5; // output pin on sensors connect A5 arduino

void setup_sensor_line() {
    pinMode(pinA5, INPUT);
}

String read_line() {
    String line_value = "L ";

    int valueA5 = analogRead(pinA5);

    line_value.concat((String) valueA5);
    line_value.concat(" ");

    line_value.concat("#");
    return line_value;

}