#define USE_RGB_INDICATOR
#ifdef USE_RGB_INDICATOR
  #define PIN_BLUE	0
  #define PIN_GREEN	0
  #define PIN_RED	0
#endif //USE_RGB_INDICATOR

#define USE_OLED_INDICATOR
#ifdef USE_OLED_INDICATOR
//may depend on individual screen. Use an I2C scanner to determine your address.
	#define I2C_ADDRESS
	#define PIN_SCL 5
	#define PIN_SDA 6
#endif