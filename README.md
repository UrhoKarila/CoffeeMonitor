# CoffeeMonitor
A simple arduino project to inform coworkers of the coffeepot status.

## Interface
The base configuration supports both a single RGB LED and a small OLED screen -- 128x32.
A single push button will be used, connecting the RST pin on the arduino to GND. Given that the device resets anytime new coffee is brewed... this is not intended to be accurate beyond about 6 hours or so.

## Materials

A cheap arduino board -- mine's an Arduino Nano clone -- any board should be good.

OLED screen - mine's a Geekcreat-branded 128x32 I2C board

Generic RGB LED

Generic pushbutton

