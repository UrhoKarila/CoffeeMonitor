#include "config.h"
#include "Adafruit_SSD1306.h"
//#include <Math>

unsigned long elapsed_time;
unsigned long old_elapsed_time;

unsigned long hours;
int minutes;
float decimal_hours;

float red_value;
float green_value;
float blue_value;

float sum_of_parts;

Adafruit_SSD1306 display(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  elapsed_time = 0;
  old_elapsed_time = 0;
  hours = 0;
  minutes = 0;

  decimal_hours = 0;

  #ifdef USE_RGB_INDICATOR
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);
    pinMode(PIN_BLUE, OUTPUT);
  #endif

  #ifdef USE_OLED_INDICATOR
    
  #endif
  #ifdef DEBUG
  Serial.println("Hello, world!");
  #endif

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

}

void loop() {
  #ifdef DEMO
    testScreen();
    testRGB();
  #else
    elapsed_time = millis();

    hours = (elapsed_time / 3600000 );
    minutes = (elapsed_time/(60000)%60);

    decimal_hours = (elapsed_time / 3600000.0 );
    //decimal_hours = (elapsed_time / 7200.0 );
      
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

  #ifdef DEBUG
  //float time_in_hours = (elapsed_time / 3600000);
  Serial.println(String("Time in hours: " + String(decimal_hours)));
  #endif

  if(decimal_hours < 8){
    red_value = (1 - (.2 * decimal_hours));
    green_value = (.25 * (1 - (.6 * abs(decimal_hours - 5.0))));
    blue_value = .25*(decimal_hours - 5.0);

    normalizeAndDisplay();
  }
  else
  {
    setColor(0,0,0);
  }

  
}

void normalizeAndDisplay(){
  if(red_value < 0)
    red_value = 0;
  if(red_value > 1)
    red_value = 1;

  if(green_value < 0)
    green_value = 0;
  if(green_value > 1)
    green_value = 1;

  if(blue_value < 0)
    blue_value = 0;
  if(blue_value > 1)
    blue_value = 1;

  sum_of_parts = red_value + green_value + blue_value;

  setColor(
    255 * (red_value/sum_of_parts),
    255 * (blue_value/sum_of_parts),
    255 * (green_value/sum_of_parts)
    );
    
  
}

void setColor(int red, int blue, int green){
  analogWrite(PIN_RED, red);
  analogWrite(PIN_BLUE, blue);
  analogWrite(PIN_GREEN, green);
}

void testRGB(){
    #ifdef DEMO
  switch((millis() /1000)%4 ){
    case 0:
      setColor(0,0,0);
      Serial.println("off");
      break;

    case 1:
      setColor(255,0,0);
      Serial.println("red");
      break;
    
    case 2:
      setColor(0,255,0);
      Serial.println("blue");
      break;
      
    case 3:
      setColor(0,0,255);
      Serial.println("green");
      break;
    
  }
  #endif
}

void updateOLED(){
  #ifdef DEBUG
  //Serial.println("Updating OLED");
  Serial.println("Elapsed Time: " + String(elapsed_time));
  Serial.println("Millis: " + String(millis()));

  Serial.println("Seconds: " + String( (elapsed_time/(1000)%60) ));
  Serial.println("Minutes: " + String( ((elapsed_time/60000)%60) ));
  Serial.println("Hours:   " + String(  (elapsed_time / 3600000 ) ));

  #endif

  //unsigned long hours = (elapsed_time / 3600000 );
  //int minutes = (elapsed_time/(60000)%60);

  if(hours < 8){
    String hour_string = String(hours);
    String minute_string = String(minutes);
  
    //Serial.println(String(hour_string + " hours, " + minute_string + " minutes old."));

    String formatted = String(hour_string + " hours, " + minute_string + " minutes old.");
    display.clearDisplay();
    display.setCursor(0,0);
    display.println(formatted);
    display.println(String("In decimal: " + String(decimal_hours)));
    display.display();
  }
  else
  {
    display.clearDisplay();
  }
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


