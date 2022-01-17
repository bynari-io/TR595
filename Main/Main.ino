// Libraries
#include <TFT_eSPI.h>
#include "tr595.h"

// Assets
#include "defaultmode.h"
#include "dm_button_red.h"
#include "dm_button_orange.h"

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
TFT_eSprite dm_bg_button = TFT_eSprite(&tft);

// Animation Elements

// **Default Mode** //
Anim dm_frameTop;
Anim dm_frameBottom;
Anim dm_button1;
Anim dm_button2;
Anim dm_button3;

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

void DrawBackgroundImage(int x, int y, int w, int h, const unsigned short IMAGE[]) {

  // Clear screen & draw background image
  //tft.fillScreen(TFT_BLACK);
  tft.pushImage(x, y, w, h, IMAGE);
      
}

void BlinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)                   
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW 
}

/////////////////////
// ANIMATION LOGIC //
/////////////////////

// ***** DEFAULT MODE *** ////////////////////////////////////////////////////////////////

void DM_InitializeAttributes(){

// Button 1
dm_button1.sizeX = 32;
dm_button1.sizeY = 12;
dm_button1.currentX = 211;
dm_button1.currentY = 214;
dm_button1.interval = 2000;

// Button 2
dm_button2.sizeX = 32;
dm_button2.sizeY = 12;
dm_button2.currentX = 245;
dm_button2.currentY = 214;
dm_button2.interval = 500;

// Button 3
dm_button3.sizeX = 32;
dm_button3.sizeY = 12;
dm_button3.currentX = 279;
dm_button3.currentY = 214;
dm_button3.interval = 750;

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

  DrawBackgroundImage(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT, defaultmode);

  while(true){

    currentMillis = millis();
    DM_FrameTop();
    DM_FrameBottom();
    DM_Button1();
    DM_Button2();
    DM_Button3();
    
  }
   
}


void DM_Button1() {
  
  if (CheckTime(currentMillis, dm_button1.previousMillis, dm_button1.interval)){

     if (dm_button1.isVisible) {
      
          DrawBackgroundImage(dm_button1.currentX, dm_button1.currentY, dm_button1.sizeX, dm_button1.sizeY, dm_button_red);
          dm_button1.isVisible = false;
          dm_button1.previousMillis = currentMillis;
          
     }
    else {
      
      dm_bg_button.createSprite(dm_button1.sizeX, dm_button1.sizeY);
      dm_bg_button.fillSprite(TFT_BLACK);
      dm_bg_button.pushSprite(dm_button1.currentX, dm_button1.currentY);
      dm_bg_button.deleteSprite();

      dm_button1.previousMillis = currentMillis;
      dm_button1.isVisible = true;
    }
  }
    
}

void DM_Button2() {
  
  if (CheckTime(currentMillis, dm_button2.previousMillis, dm_button2.interval)){

     if (dm_button2.isVisible) {
      
          DrawBackgroundImage(dm_button2.currentX, dm_button2.currentY, dm_button2.sizeX, dm_button2.sizeY, dm_button_orange);
          dm_button2.isVisible = false;
          dm_button2.previousMillis = currentMillis;
          
     }
    else {
      
      dm_bg_button.createSprite(dm_button2.sizeX, dm_button2.sizeY);
      dm_bg_button.fillSprite(TFT_BLACK);
      dm_bg_button.pushSprite(dm_button2.currentX, dm_button2.currentY);
      dm_bg_button.deleteSprite();

      dm_button2.previousMillis = currentMillis;
      dm_button2.isVisible = true;
    }
  }
    
}

void DM_Button3() {
  
  if (CheckTime(currentMillis, dm_button3.previousMillis, dm_button3.interval)){

     if (dm_button3.isVisible) {
      
          DrawBackgroundImage(dm_button3.currentX, dm_button3.currentY, dm_button3.sizeX, dm_button3.sizeY, dm_button_orange);
          dm_button3.isVisible = false;
          dm_button3.previousMillis = currentMillis;
          
     }
    else {
      
      dm_bg_button.createSprite(dm_button3.sizeX, dm_button3.sizeY);
      dm_bg_button.fillSprite(TFT_BLACK);
      dm_bg_button.pushSprite(dm_button3.currentX, dm_button3.currentY);
      dm_bg_button.deleteSprite();

      dm_button3.previousMillis = currentMillis;
      dm_button3.isVisible = true;
    }
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
