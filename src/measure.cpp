
#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//I2C setup
#include <Wire.h>

#include "screenDisplay.cpp"

void displayADC(void);
void voltsMeas(void);
void ampsMeas(void);
void ohmsMeas(void); //continuity included?

//variable declarations
int sensorPin = A0;  // input pin for the potentiometer
double val = 0;

void displayADC(void) 
{
    for(int x = 0; x < 5000; x++) 
    {
      val += analogRead(sensorPin);
     }

    val = val / 5000.0;

    //display.clearDisplay();

    double Vin = ((val / 65535.00) * 3.3266) + 0.00555;

    //tink about later 
    char cstr[4] ;
    Serial.print(Vin, 5);
    Serial.print("\n");
    display.setCursor(0, 0);
    display.print(Vin, 5);
    display.print("V");
    int getArrayLength = sizeof(cstr) / sizeof(int);

    // for (int i = 1; i < 5 ; i++)
    // {
    //    display.writeLine(cstr[i - 1]);
    //    display.setCursor(i * 23, 0);
    // }
    display.display();
    //Serial.print("\n");
    //delay(100);
}

void voltsMeas(void)
{

}

void ampsMeas(void)
{

}

void ohmsMeas(void)
{

}