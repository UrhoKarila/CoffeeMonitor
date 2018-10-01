#include "config.h"
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);

  #ifdef USE_RGB_INDICATOR
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
  #endif

  #ifdef USE_OLED_INDICATOR
    pinMode(PIN_SCL, OUTPUT);
    pinMode(PIN_SDA, OUTPUT);
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:

}
