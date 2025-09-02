#include <Arduino.h>
#include <FastLED.h>
#define MA_BROCHE_ANGLE 32

CRGB pixelAtom;

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1);
}

void loop() {
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  Serial.print(maLectureAnalogique);
  Serial.println();
  delay(100);

  /*if (maLectureAnalogique > 4095 / 2) {
    pixelAtom = CRGB(242,165,56);
    FastLED.show();
  } else {
    pixelAtom = CRGB(0,0,0);
    FastLED.show();
  }*/

  int valeurRouge = maLectureAnalogique * 255 / 4095;
  pixelAtom = CRGB(valeurRouge,0,0);
  FastLED.show();

}
