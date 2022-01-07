// Libraries
#include <TFT_eSPI.h>

// Assets
#include "lcars.h"

// Constants
const int DISPLAY_WIDTH = 320;
const int DISPLAY_HEIGHT = 240;

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

void setup() {
  
  TFTSetup();
  DrawBackgroundImage(lcars);
}

void loop() { 

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
