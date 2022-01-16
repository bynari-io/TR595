// Libraries
#include <TFT_eSPI.h>
#include "tr595.h"

// Assets
#include "defaultmode.h"

//TFT_eSPI instance
TFT_eSPI tft = TFT_eSPI();

// Constants
const int DISPLAY_WIDTH = 320;
const int DISPLAY_HEIGHT = 240;

// Sprites

TFT_eSprite dm_spr_frameTop = TFT_eSprite(&tft);
TFT_eSprite dm_bg_frameTop = TFT_eSprite(&tft);
TFT_eSprite dm_spr_frameBottom = TFT_eSprite(&tft);
TFT_eSprite dm_bg_frameBottom = TFT_eSprite(&tft);

// Animation Elements

// **Default Mode** //
Anim dm_frameTop;
Anim dm_frameBottom;

// Variables
unsigned long currentMillis = 0;

// Functions

void setup() {

  pinMode(LED_BUILTIN, OUTPUT); // Used for diagnostic purposes
  
  // Initialize TFT & clear the screen
  TFTSetup();
  tft.fillScreen(TFT_BLACK);

  //Initialize all modes
  DM_InitializeAttributes();

  // Begin Default Mode animation sequence
  DM_Loop();
 
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

void DrawBackgroundImage(int x, int y, const unsigned short IMAGE[]) {

  // Clear screen & draw background image
  tft.fillScreen(TFT_BLACK);
  tft.pushImage(x, y, DISPLAY_WIDTH, DISPLAY_HEIGHT, IMAGE);
      
}

void BlinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}

/////////////////////
// ANIMATION LOGIC //
/////////////////////

// ***** DEFAULT MODE *** ////////////////////////////////////////////////////////////////
// ***** DEFAULT MODE *** ////////////////////////////////////////////////////////////////
// ***** DEFAULT MODE *** ////////////////////////////////////////////////////////////////

void DM_InitializeAttributes(){

// Frame Top
dm_frameTop.sizeX = 8;
dm_frameTop.sizeY = 5;
dm_frameTop.minX = 136;
dm_frameTop.minY = 59;
dm_frameTop.maxX = 173;
dm_frameTop.maxY = 59;
dm_frameTop.currentX = dm_frameTop.maxX;
dm_frameTop.currentY = dm_frameTop.minY;
dm_frameTop.oldX = dm_frameTop.currentX;
dm_frameTop.oldY = dm_frameTop.currentY;
dm_frameTop.reverse = true;
dm_frameTop.interval = 20;

// Frame Bottom
dm_frameBottom.sizeX = 8;
dm_frameBottom.sizeY = 5;
dm_frameBottom.minX = 136;
dm_frameBottom.minY = 230;
dm_frameBottom.maxX = 173;
dm_frameBottom.maxY = 230;
dm_frameBottom.currentX = dm_frameBottom.minX;
dm_frameBottom.currentY = dm_frameBottom.minY;
dm_frameBottom.oldX = dm_frameBottom.currentX;
dm_frameBottom.oldY = dm_frameBottom.currentY;
dm_frameBottom.reverse = false;
dm_frameBottom.interval = 20;

}

// Begin Default Mode Loop
void DM_Loop(){

  DrawBackgroundImage(0, 0, defaultMode);

  while(true){

    currentMillis = millis();
    DM_FrameTop();
    DM_FrameBottom();
    
  }
   
}

// Frame Top
void DM_FrameTop() {

  if (CheckTime(currentMillis, dm_frameTop.previousMillis, dm_frameTop.interval)) {

    // Draw background sprite to erase previous drawing
    dm_bg_frameTop.createSprite(dm_frameTop.sizeX, dm_frameTop.sizeY);
    dm_bg_frameTop.fillSprite(TFT_BLACK);
    dm_bg_frameTop.pushSprite(dm_frameTop.oldX, dm_frameTop.oldY);
    dm_bg_frameTop.deleteSprite();

    // Draw sprite at new location
    dm_spr_frameTop.createSprite(dm_frameTop.sizeX, dm_frameTop.sizeY);
    dm_spr_frameTop.fillSprite(TFT_RED);
    dm_spr_frameTop.pushSprite(dm_frameTop.currentX, dm_frameTop.currentY);
    dm_spr_frameTop.deleteSprite();

    dm_frameTop.oldX = dm_frameTop.currentX;

    if (!dm_frameTop.reverse){
      dm_frameTop.currentX++;
    }
    else {
      dm_frameTop.currentX--;
    }

    if (dm_frameTop.currentX <= dm_frameTop.minX) { dm_frameTop.reverse = false; }
    if (dm_frameTop.currentX >= dm_frameTop.maxX) { dm_frameTop.reverse = true; }

    dm_frameTop.previousMillis = currentMillis;
    
  }  
}

// Frame Bottom
void DM_FrameBottom() {

  if (CheckTime(currentMillis, dm_frameBottom.previousMillis, dm_frameBottom.interval)) {

    // Draw background sprite to erase previous drawing
    dm_bg_frameBottom.createSprite(dm_frameBottom.sizeX, dm_frameBottom.sizeY);
    dm_bg_frameBottom.fillSprite(TFT_BLACK);
    dm_bg_frameBottom.pushSprite(dm_frameBottom.oldX, dm_frameBottom.oldY);
    dm_bg_frameBottom.deleteSprite();

    // Draw sprite at new location
    dm_spr_frameBottom.createSprite(dm_frameBottom.sizeX, dm_frameBottom.sizeY);
    dm_spr_frameBottom.fillSprite(TFT_RED);
    dm_spr_frameBottom.pushSprite(dm_frameBottom.currentX, dm_frameBottom.currentY);
    dm_spr_frameBottom.deleteSprite();

    dm_frameBottom.oldX = dm_frameBottom.currentX;

    if (!dm_frameBottom.reverse){
      dm_frameBottom.currentX++;
    }
    else {
      dm_frameBottom.currentX--;
    }

    if (dm_frameBottom.currentX <= dm_frameBottom.minX) { dm_frameBottom.reverse = false; }
    if (dm_frameBottom.currentX >= dm_frameBottom.maxX) { dm_frameBottom.reverse = true; }

    dm_frameBottom.previousMillis = currentMillis;
    
  }  
}
