# Arduino-Timer
A basic and rough Timer library for the Arduino

## Installation
* Download a copy of the current library
* Navigate to Documents/Arduino/libraries
* Unpack the library there
* Open the Arduino IDE and #include <timer.h>;

## What it is for
This is a very small and rough library for looping and non-looping timers. It is useful for triggering a function every n milliseconds, or reading values out of a sensor. There are lots of timer libraries for the Arduino. This one is about keeping it to the barebones.

## Usage
Reading values out of pin 4 every 100ms

    #include <timer.h>;
    #define BUTTON_PIN 4
    
    Timer timer;
    
    void setup() {
      Serial.begin( 9600 );
      pinMode( BUTTON_PIN, INPUT );
      timer.start( 100, true );
    }

    void loop() {
      if ( timer.isFinished() ) {
        int val = digitalRead( BUTTON_PIN );
        Serial.println( val );
      }
    }

## Overview
