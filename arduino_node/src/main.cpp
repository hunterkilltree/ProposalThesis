#include <Arduino.h>
#include <./SensorControl.h>
#include <./SensorPos.h>
#include <./TestPin.h>
#include <./SensorLine.h>
#include <./Debug.h>
// #include
// for rosserial
// #include <ros.h>
// #include <ros/time.h>
// #include <std_msgs/Int32.h>

char jetson_command;

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
  if (Serial.available() > 0)
  {
    jetson_command = Serial.read();

    if (jetson_command == 'f')
    {
      run_forward();
    }
    else if (jetson_command == 'b')
    {
      run_backward();
    }
    else if (jetson_command == 's') {
      run_stop();
    }
  }

  String all_sensor_value = "A";
  String pos_value = "";
  String line_value = "";

  pos_value = read_pos();
  line_value = read_line();

  // pos_value.remove(1); // remove /n

  if (pos_value == "" )
  {
    pos_value = "P#";
  }
  if (line_value == "") {
    line_value = "L#";
  }

  all_sensor_value.concat(pos_value);
  all_sensor_value.concat(line_value);
  print_string(all_sensor_value);
  // delay(50);
}