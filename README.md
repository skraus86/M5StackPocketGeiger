M5StackPocketGeiger
Simple Geiger Counter using Pocket Geiger and M5 Stack

Project Includes Code from Radiation Watch
https://github.com/MonsieurV/ArduinoPocketGeiger
Also includes M5Stack Code from
https://github.com/m5stack/M5Stack
You will need to go into your RadiationWatch.h file in C:\Users\YOURNAMEHERE\Documents\Arduino\libraries\RadiationWatch\src
And change pins, as Pin 3 will not provide good resolution on the ESP32 in the M5Stack.
Pins utilized for Pocket Geiger - signPin = 2, noisePin = 5
