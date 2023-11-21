
#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//I2C setup
#include <Wire.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//func declarations
void bootScreen(void);


void bootScreen(void)
{
    //display setup      
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
     }
     //displayTest();
    Serial.begin(9600);
    display.display();
    delay(200); 
    display.clearDisplay();

     display.clearDisplay();
  
    display.setTextSize(3);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner
    display.cp437(true);


    pinMode(LED_BUILTIN, OUTPUT);
   
    display.display();
    delay(200); 
    display.clearDisplay();
    ////display.write(48);
     display.display();
    delay(200); 
    display.clearDisplay();

    display.clearDisplay();

    display.setTextSize(3);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(64, 32);     // Start at top-left corner
    display.cp437(true);         // Use full 256 char 'Code Page 437' font

    display.write("A");

    display.setCursor(64, 0); 
     display.write(16);

     display.display();
}