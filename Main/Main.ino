// Libraries
#include <TFT_eSPI.h>

// Assets
#include "lcars.h"

//TFT_eSPI instance
TFT_eSPI tft = TFT_eSPI();

// Constants
const int DISPLAY_WIDTH = 320;
const int DISPLAY_HEIGHT = 240;

// Sprite Setup

TFT_eSprite sprite = TFT_eSprite(&tft);
TFT_eSprite background = TFT_eSprite(&tft);

// Variables
int minY = 50;
int maxY = 180;
int spriteY = minY;
int oldY = minY;

bool movingDown = true;




void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  // Initialize TFT
  TFTSetup();

  // Clear the screen
  tft.fillScreen(TFT_BLACK);
  
  DrawBackgroundImage(lcars);

  
}

void loop() { 

  background.createSprite(5, 10);
  background.fillSprite(TFT_BLACK);
  background.pushSprite(80, oldY);
  background.deleteSprite();
  
  sprite.createSprite(5, 10);
  sprite.fillSprite(TFT_RED);
  sprite.pushSprite(80, spriteY);
  sprite.deleteSprite();
  oldY = spriteY;
  delay(10);
  if (movingDown){ 
   spriteY++;  
  }
  else {
   spriteY--;
   
  }

  if (spriteY <= minY) { movingDown = true; }
  if (spriteY >= maxY) { movingDown = false; }
  

}

void TFTSetup(){

  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1); // Set display to landscape

  //Swap the color byte order when rendering
  tft.setSwapBytes(true);
  
}

void DrawBackgroundImage(const unsigned short IMAGE[]) {

  // Clear screen to black
  tft.fillScreen(TFT_BLACK);

  // Draw the background image
  tft.pushImage(0,0, DISPLAY_WIDTH, DISPLAY_HEIGHT, IMAGE);
      
}

void BlinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}
