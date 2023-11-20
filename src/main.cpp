// Goal: send analog voltage from Power Supply and read from ADC (with autoRanging) and display on I2C screen

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

//func prototypes
void displayTest(void);
void testdrawrect(void);
void displayADC(void);
int sensorPin = A0;  // input pin for the potentiometer
double digitalValue = 0.00;// variable to store the value coming from the sensor



void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  analogReadResolution(16);

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
  
}

void loop() {

  displayADC();
  
}










void displayADC(void) 
{
  double val = 0;
  for(int x = 0; x < 5000; x++) 
  {
    val += analogRead(sensorPin);
  }
  val = val / 5000.0;

  display.clearDisplay();

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


void displayTest(void) 
{
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


