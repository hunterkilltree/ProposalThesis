#include <Arduino.h>

#define enA 4
#define inA1 3
#define inA2 2

int moveSpeed = 200;
uint8_t moveSpeed_FW = 0;
uint8_t moveSpeed_BW = 0;

unsigned char stop_flag = 0;

void setup_sensor_control()
{
    pinMode(enA, OUTPUT);
    pinMode(inA1, OUTPUT);
    pinMode(inA2, OUTPUT);

    // TODO : for 4 wheel

    // TODO
}

void run_forward()
{
    moveSpeed_FW = moveSpeed;

    digitalWrite(inA1, HIGH);
    digitalWrite(inA2, LOW);

    analogWrite(enA, moveSpeed_FW);
}

void run_backward()
{
    moveSpeed_BW = moveSpeed;

    digitalWrite(inA1, LOW);
    digitalWrite(inA2, HIGH);

    analogWrite(enA, moveSpeed_BW);
}

//  left 90 degree
void rotate_left()
{
}

//  right 90 degree
void rotate_right()
{
}

void speed_up()
{
}

void speed_down()
{
}

void run_stop()
{
    analogWrite(enA, 0);
}

// for future  mecanum; bo ko biet lam
void run_right()
{
}

void run_left()
{
}

void run_right_up()
{
}

void run_left_up()
{
}

void run_right_down()
{
}

void run_left_down()
{
}
