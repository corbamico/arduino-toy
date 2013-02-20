/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Ultrasonic.h>
#include <Tone.h>

// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
//Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
Adafruit_PCD8544 display = Adafruit_PCD8544(49,47,45,43,41);
Ultrasonic       sonic   = Ultrasonic(12,13);

const int  NOTES[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTES_G4,NOTE_A5,NOTE_B5,NOTE_C5,0};

void setup()   {
  //51 VCC
  //53 BL
  pinMode(51,OUTPUT);
  digitalWrite(51,HIGH);
  pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);
 
  //11 VCC for ultrasonic 
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  
 
  Serial.begin(9600);

  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);

  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
}


void loop() {
  long distant;
  int  note=0;
  distant = sonic.Ranging(CM);
  // text display tests
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Read From Light Sensor:");
  display.print("Distant:");display.println(distant);
  note = map(distant,0,51,0,8);

  display.print("Note:");display.println(note);
  display.display();
  delay(50);
}
 


