#include <Arduino.h>
#include <./SensorControl.h>
#include <./SensorPos.h>
#include <./TestPin.h>
#include <./Debug.h>
// #include

void setup()
{
  // put your setup code here, to run once:
  setup_sensor_pos();
  delay(300);

  setup_sensor_control();
  delay(300);

  setup_debug();
  delay(300);

  delay(300);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // run_backward();
  // debug(printf("hello world");)
  // Serial.println("hello");

  // run_forward();

  // delay(2000);

  // run_stop();

  // delay(5000);
  String pos_value = "";
  pos_value = read_pos();
  if (pos_value != "false" && pos_value != "")
  {
    print_string(pos_value);
  }
}