#include "config.h"
#include "Adafruit_SSD1306.h"

unsigned long elapsed_time;
unsigned long old_elapsed_time;

Adafruit_SSD1306 display(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  elapsed_time = 0;
  old_elapsed_time = 0;

  #ifdef USE_RGB_INDICATOR
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
  #endif

  #ifdef USE_OLED_INDICATOR
    
  #endif
  Serial.println("Hello, world!");

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

}

void loop() {
  #ifdef DEBUG
    testScreen();
  #else
    elapsed_time = millis();
    if(elapsed_time - old_elapsed_time > (UPDATE_FREQ * 1000)){
    #ifdef USE_RGB_INDICATOR
      updateRGB();
    #endif
    #ifdef USE_OLED_INDICATOR
      updateOLED();
    #endif
      old_elapsed_time = elapsed_time;
    }
  #endif
  delay(500);

}

void updateRGB(){
  
}

void updateOLED(){
  #ifdef DEBUG
  //Serial.println("Updating OLED");
  Serial.println("Elapsed Time: " + String(elapsed_time));
  Serial.println("Millis: " + String(millis()));

  Serial.println("Seconds: " + String( (elapsed_time/(1000)%60) ));
  Serial.println("Minutes: " + String( ((elapsed_time/60000)%60) ));
  Serial.println("Hours:   " + String(  (elapsed_time / 3600000 ) ));
  
  unsigned long hours = (elapsed_time / 3600000 );
  int minutes = (elapsed_time/(60000)%60);

  String hour_string = String(hours);
  String minute_string = String(minutes);
  #endif

  //Serial.println(String(hour_string + " hours, " + minute_string + " minutes old."));

  String formatted = String(hour_string + " hours, " + minute_string + " minutes old.");
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(formatted);
  display.display();
}

void testScreen(){
    // put your main code here, to run repeatedly:
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.display();
  delay(2000);
  
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.display();
  delay(2000);
  
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  delay(2000);
  display.clearDisplay();
}

