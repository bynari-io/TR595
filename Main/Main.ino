// Libraries
#include <TFT_eSPI.h>
#include "tr595.h"

// Assets
#include "lcars.h"

//TFT_eSPI instance
TFT_eSPI tft = TFT_eSPI();

// Constants
const int DISPLAY_WIDTH = 320;
const int DISPLAY_HEIGHT = 240;

// Sprites
TFT_eSprite dm_spr_scannerBarL = TFT_eSprite(&tft);
TFT_eSprite dm_bg_scannerBarL = TFT_eSprite(&tft);
TFT_eSprite dm_spr_scannerBarR = TFT_eSprite(&tft);
TFT_eSprite dm_bg_scannerBarR = TFT_eSprite(&tft);


// Animation Elements
Anim dm_scannerBarL;
Anim dm_scannerBarR;

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

void DrawBackgroundImage(const unsigned short IMAGE[]) {

  // Clear screen & draw background image
  tft.fillScreen(TFT_BLACK);
  tft.pushImage(0,0, DISPLAY_WIDTH, DISPLAY_HEIGHT, IMAGE);
      
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

// Left Scanner Bar
dm_scannerBarL.sizeX = 5;
dm_scannerBarL.sizeY = 10;
dm_scannerBarL.minY = 50;
dm_scannerBarL.maxY = 180;
dm_scannerBarL.currentX = 80;
dm_scannerBarL.currentY = dm_scannerBarL.minY;
dm_scannerBarL.oldX = dm_scannerBarL.currentX;
dm_scannerBarL.oldY = dm_scannerBarL.minY;
dm_scannerBarL.reverse = false;
dm_scannerBarL.interval = 10;

// Right Scanner Bar
dm_scannerBarR.sizeX = 5;
dm_scannerBarR.sizeY = 10;
dm_scannerBarR.minY = 50;
dm_scannerBarR.maxY = 180;
dm_scannerBarR.currentX = 297;
dm_scannerBarR.currentY = dm_scannerBarR.maxY;
dm_scannerBarR.oldX = dm_scannerBarR.currentX;
dm_scannerBarR.oldY = dm_scannerBarR.minY;
dm_scannerBarR.reverse = true;
dm_scannerBarR.interval = 10;

}

// Begin Default Mode Loop
void DM_Loop(){

  DrawBackgroundImage(defaultMode);

  while(true){

    currentMillis = millis();
    DM_Ele_ScannerBarL();
    DM_Ele_ScannerBarR();
    
  }
   
}


// Left Scanner Bar
void DM_Ele_ScannerBarL(){

  if ((currentMillis - dm_scannerBarL.previousMillis) > dm_scannerBarL.interval){

    dm_bg_scannerBarL.createSprite(dm_scannerBarL.sizeX, dm_scannerBarL.sizeY);
    dm_bg_scannerBarL.fillSprite(TFT_BLACK);
    dm_bg_scannerBarL.pushSprite(dm_scannerBarL.oldX, dm_scannerBarL.oldY);
    dm_bg_scannerBarL.deleteSprite();
  
    dm_spr_scannerBarL.createSprite(dm_scannerBarL.sizeX, dm_scannerBarL.sizeY);
    dm_spr_scannerBarL.fillSprite(TFT_RED);
    dm_spr_scannerBarL.pushSprite(dm_scannerBarL.currentX, dm_scannerBarL.currentY);
    dm_spr_scannerBarL.deleteSprite();
    dm_scannerBarL.oldY = dm_scannerBarL.currentY;
  
    if (!dm_scannerBarL.reverse){ 
    dm_scannerBarL.currentY++;  
    }
    
    else {      
      dm_scannerBarL.currentY--;   
    }

    if (dm_scannerBarL.currentY <= dm_scannerBarL.minY) { dm_scannerBarL.reverse = false; }
    if (dm_scannerBarL.currentY >= dm_scannerBarL.maxY) { dm_scannerBarL.reverse = true; }

    dm_scannerBarL.previousMillis = currentMillis;
    
  }
}

// Right Scanner Bar
void DM_Ele_ScannerBarR(){

  if ((currentMillis - dm_scannerBarR.previousMillis) > dm_scannerBarR.interval){

    dm_bg_scannerBarR.createSprite(dm_scannerBarR.sizeX, dm_scannerBarR.sizeY);
    dm_bg_scannerBarR.fillSprite(TFT_BLACK);
    dm_bg_scannerBarR.pushSprite(dm_scannerBarR.oldX, dm_scannerBarR.oldY);
    dm_bg_scannerBarR.deleteSprite();
  
    dm_spr_scannerBarR.createSprite(dm_scannerBarR.sizeX, dm_scannerBarR.sizeY);
    dm_spr_scannerBarR.fillSprite(TFT_RED);
    dm_spr_scannerBarR.pushSprite(dm_scannerBarR.currentX, dm_scannerBarR.currentY);
    dm_spr_scannerBarR.deleteSprite();
    dm_scannerBarR.oldY = dm_scannerBarR.currentY;
  
    if (!dm_scannerBarR.reverse){ 
    dm_scannerBarR.currentY++;  
    }
    
    else {      
      dm_scannerBarR.currentY--;   
    }

    if (dm_scannerBarR.currentY <= dm_scannerBarR.minY) { dm_scannerBarR.reverse = false; }
    if (dm_scannerBarR.currentY >= dm_scannerBarR.maxY) { dm_scannerBarR.reverse = true; }

    dm_scannerBarR.previousMillis = currentMillis;
    
  }
}
