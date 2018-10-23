//#define DEBUG

#define USE_RGB_INDICATOR
#ifdef USE_RGB_INDICATOR
  #define PIN_BLUE	9
  #define PIN_GREEN	10
  #define PIN_RED	11
#endif //USE_RGB_INDICATOR

#define UPDATE_FREQ 1

#define USE_OLED_INDICATOR
#ifdef USE_OLED_INDICATOR
//may depend on individual screen. Use an I2C scanner to determine your address.
	#define I2C_ADDRESS 0x3C
#endif

//started at 9:46