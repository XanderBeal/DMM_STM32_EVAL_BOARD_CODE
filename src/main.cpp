#include <Arduino.h>


// Goal: send analog voltage from Power Supply and read from ADC (with autoRanging) and display on I2C screen


// put function declarations here:
int myFunction(int, int);


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PB9, 1);
  delay(400);
  digitalWrite(PB9, 0);
  delay(400);
  //printf(i);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}