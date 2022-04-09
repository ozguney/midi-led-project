#include <Adafruit_NeoPixel.h> // Add Led Library
#define PIN 6
#define NUM_LEDS 88
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
#define RedDensity    150
#define GreenDensity  199
#define BlueDensity   88
byte note; // for mathematical operation

void OnNoteOn(byte channel, byte note, byte velocity) {
    strip.setPixelColor(note-20, RedDensity, GreenDensity, BlueDensity);
    strip.show();
    digitalWrite(LED_BUILTIN, HIGH); // For feedback
}

void OnNoteOff(byte channel, byte note, byte velocity) {
    strip.setPixelColor(note-20, 0, 0, 0);
    strip.show();
    digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW); // Blinks LED Once
  
  strip.begin(); // starts the strip and blanks it out
  strip.show();
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
}

void loop() {
    usbMIDI.read();
}
