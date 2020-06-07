#include "RadiationWatch.h"
#include "M5Stack.h"
/*
Project Includes Code from Radiation Watch
https://github.com/MonsieurV/ArduinoPocketGeiger
Also includes M5Stack Code from
https://github.com/m5stack/M5Stack
/*signPin = 2, noisePin = 5*/

RadiationWatch radiationWatch;

void onRadiation()
{
  Serial.println("A wild gamma ray appeared");
  Serial.print(radiationWatch.uSvh());
  Serial.print(" uSv/h +/- ");
  Serial.println(radiationWatch.uSvhError());
}

void onNoise()
{
  Serial.println("Argh, noise, please stop moving");
}

void setup()
{
  Serial.begin(9600);
  radiationWatch.setup();
  // Register the callbacks.
  radiationWatch.registerRadiationCallback(&onRadiation);
  radiationWatch.registerNoiseCallback(&onNoise);
  M5.Lcd.begin(); /*Enable M5 LCD*/
  M5.Lcd.setTextSize(3);
}

void loop()
{
  radiationWatch.loop();
  M5.Lcd.setCursor(0,0); /*cursor top left*/
  M5.Lcd.print(radiationWatch.uSvh());
  M5.Lcd.print(" uSv/h +/- ");
  M5.Lcd.print("\n");
  M5.Lcd.print(radiationWatch.cpm());
  M5.Lcd.print("cpm");
}
