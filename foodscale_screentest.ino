#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);

  display.display();//show buffer, initialized with adafruit logo
  delay(500);
   
  display.clearDisplay();// Clear the buffer.
  display.display();
  
  //display.drawLine(0,0,0,32,WHITE); //col, ligne, col, ligne
  //display.display();
}

void loop() {
  int i=0;
  for (i=0;i<128;i++)
  {
    display.drawLine(i,0,i,32,WHITE);
    display.display();
    delay(50);
    display.clearDisplay();
  }
}
