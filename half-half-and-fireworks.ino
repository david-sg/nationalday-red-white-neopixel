/*
  Use neopixels to display red and white, flag like pattern
  flash red/white like fireworks

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define LED_PIN 3
#define NUM_LEDS 24

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Colors!
const uint32_t white = strip.Color(255, 255, 255);
const uint32_t black =   strip.Color(0, 0, 0);
const uint32_t red =   strip.Color(255, 0, 0);
const int MaximumBrightness = 100;

void setup() {
  randomSeed(analogRead(0));
  strip.begin();
  strip.setBrightness(30);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  //  DimDisplay(red);
  //  delay(1000);
  //  DimDisplay(white);
  //  delay(1000);
  Flag(red, white);
  delay(10000);
//  Flag2(red, white);
//  delay(10000);
  for (int i = 0; i <  20; i++) {
    Fireworks(red, white);
  }

}


void DimDisplay(uint32_t color) {
  strip.setBrightness(0);
  int TOTAL_LEDS = NUM_LEDS;
  float StepDelay = 5; // ms for a step delay on the lights

  // fade in
  for (int i = 0; i <  MaximumBrightness; i++) {
    strip.setBrightness(i);
    // Now set every LED to that color
    for (int ledNumber = 0; ledNumber < TOTAL_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, color);
    }
    strip.show();
    delay(StepDelay);
  }
  delay(1000);
  // fade out
  for (int i = MaximumBrightness; i >  -1; i--) {
    strip.setBrightness(i);
    // Now set every LED to that color
    for (int ledNumber = 0; ledNumber < TOTAL_LEDS; ledNumber++) {
      strip.setPixelColor(ledNumber, color);
    }
    strip.show();
    delay(StepDelay);
  }
  delay(1000);

}


void Fireworks(uint32_t color1, uint32_t color2) {
  int randNumber1 = random(NUM_LEDS);
  int   randNumber2 = random(NUM_LEDS);
  while ( randNumber1 == randNumber2) {
    randNumber2 = random(NUM_LEDS);
  }

  for (int i = 10; i <  MaximumBrightness; i++) {
    strip.setBrightness(i);
    strip.setPixelColor(randNumber1, color1);
    strip.show();
  }
  delay(100);
  strip.setBrightness(0);
  strip.setPixelColor(randNumber1, color1);
  for (int i = 10; i <  MaximumBrightness; i++) {
    strip.setBrightness(i);
    strip.setPixelColor(randNumber2, color2);
    strip.show();
  }
  delay(100);
  strip.setBrightness(0);
  strip.setPixelColor(randNumber1, color2);
}


void Flag2(uint32_t color1, uint32_t color2) {
  strip.setBrightness(100);
  int top_flag = NUM_LEDS / 2;
  for (int ledNumber = 0; ledNumber < top_flag; ledNumber++) {
    strip.setPixelColor(ledNumber, color1);
  }
  for (int ledNumber = top_flag; ledNumber < NUM_LEDS; ledNumber++) {
    strip.setPixelColor(ledNumber, color2);
  }
  strip.show();
}



void Flag(uint32_t color1, uint32_t color2) {
  strip.setBrightness(100);
  int top_flag = NUM_LEDS / 2;
  for (int ledNumber = 0; ledNumber < top_flag; ledNumber++) {
    strip.setPixelColor(ledNumber, color1);
  }


  for (int ledNumber = top_flag; ledNumber < NUM_LEDS; ledNumber++) {
    strip.setPixelColor(ledNumber, color2);
  }
//  strip.setPixelColor(17, color1);
  
  strip.show();
}
