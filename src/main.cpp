
#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//I2C setup
#include <Wire.h>

//import files
#include "measure.hpp"
#include "cal.hpp"
#include "screenDisplay.hpp"


//variable declarations
double digitalValue = 0.00;// variable to store the value coming from the sensor



//One time executed code
void setup() {

  //bootScreen(); //from display.cpp

  analogReadResolution(16); //set bit count of ADC

  //displayTest();
  //Serial.begin(9600);  //serial setup for PC debugging

/*
  display.display();
  delay(200); 
  display.clearDisplay();
  display.clearDisplay();
  
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);


  pinMode(LED_BUILTIN, OUTPUT);
  */
}

//Repeated code loop (allows the processor to continue opperating without needing manuealy reset)
void loop() {

  /* 
  General structure:
  - Ensure all gpio is set to low and nothing is configured on 
  - Display 
      - Startup screen
      - Display options (volts, amps, ohms, cal / rel)  
          - Buttons (single press for mode selection, another press for mode deactivation)
          - Ohms mode can have LED_Test blink when in continuity mode (< 10 Ohms resistance)
  - Configure ADC to mode
  - Take measurements
  - Take average according to mode
  - Store / display results
  */


  //displayADC();
  
}


