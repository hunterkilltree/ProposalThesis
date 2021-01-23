#include <Arduino.h>

#define debug(X) X
#define printf Serial.println

void setup_debug()
{
    Serial.begin(9600);
    debug(printf("Set up debug ok");)
}

void print_string(String str) 
{
    debug(printf(str));
}