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

// **Default Mode** //
TFT_eSprite dm_spr_frameTop = TFT_eSprite(&tft);
TFT_eSprite dm_bg_frameTop = TFT_eSprite(&tft);
TFT_eSprite dm_spr_frameBottom = TFT_eSprite(&tft);
TFT_eSprite dm_bg_frameBottom = TFT_eSprite(&tft);
TFT_eSprite dm_bg_button = TFT_eSprite(&tft);
TFT_eSprite dm_spr_barGraph = TFT_eSprite(&tft);
TFT_eSprite dm_bg_barGraph = TFT_eSprite(&tft);

// Animation Elements

// **Default Mode** //
Anim dm_frameTop;
Anim dm_frameBottom;
Anim dm_button1;
Anim dm_button2;
Anim dm_button3;
Anim dm_bargraph1;
Anim dm_bargraph2;
Anim dm_bargraph3;
Anim dm_bargraph4;
Anim dm_bargraph5;
Anim dm_bargraph6;
Anim dm_bargraph7;
Anim dm_bargraph8;

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
  randomSeed(millis());

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

void ShowLED() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)                   
}

/////////////////////
// ANIMATION LOGIC //
/////////////////////

// ***** DEFAULT MODE *** ////////////////////////////////////////////////////////////////

void DM_InitializeAttributes(){

// Bargraph 1
dm_bargraph1.sizeX = 23;
dm_bargraph1.sizeY = 5;
dm_bargraph1.maxX = 23;
dm_bargraph1.maxY = 95;
dm_bargraph1.currentX = 90;
dm_bargraph1.currentY = dm_bargraph1.bargraphBottom - dm_bargraph1.sizeY;
dm_bargraph1.bargraphBottom = 188;
dm_bargraph1.interval = 20;
dm_bargraph1.bargraphSpeed = 1;

// Bargraph 2
dm_bargraph2.sizeX = 23;
dm_bargraph2.sizeY = 5;
dm_bargraph2.maxX = 23;
dm_bargraph2.maxY = 95;
dm_bargraph2.currentX = 115;
dm_bargraph2.currentY = dm_bargraph2.bargraphBottom - dm_bargraph2.sizeY;
dm_bargraph2.bargraphBottom = 188;
dm_bargraph2.interval = 20;
dm_bargraph2.bargraphSpeed = 1;

// Bargraph 3
dm_bargraph3.sizeX = 23;
dm_bargraph3.sizeY = 5;
dm_bargraph3.maxX = 23;
dm_bargraph3.maxY = 95;
dm_bargraph3.currentX = 140;
dm_bargraph3.currentY = dm_bargraph1.bargraphBottom - dm_bargraph1.sizeY;
dm_bargraph3.bargraphBottom = 188;
dm_bargraph3.interval = 20;
dm_bargraph3.bargraphSpeed = 1;

// Bargraph 4
dm_bargraph4.sizeX = 23;
dm_bargraph4.sizeY = 5;
dm_bargraph4.maxX = 23;
dm_bargraph4.maxY = 95;
dm_bargraph4.currentX = 165;
dm_bargraph4.currentY = dm_bargraph4.bargraphBottom - dm_bargraph4.sizeY;
dm_bargraph4.bargraphBottom = 188;
dm_bargraph4.interval = 20;
dm_bargraph4.bargraphSpeed = 1;

// Bargraph 5
dm_bargraph5.sizeX = 23;
dm_bargraph5.sizeY = 5;
dm_bargraph5.maxX = 23;
dm_bargraph5.maxY = 95;
dm_bargraph5.currentX = 190;
dm_bargraph5.currentY = dm_bargraph5.bargraphBottom - dm_bargraph5.sizeY;
dm_bargraph5.bargraphBottom = 188;
dm_bargraph5.interval = 20;
dm_bargraph5.bargraphSpeed = 1;

// Bargraph 6
dm_bargraph6.sizeX = 23;
dm_bargraph6.sizeY = 5;
dm_bargraph6.maxX = 23;
dm_bargraph6.maxY = 95;
dm_bargraph6.currentX = 215;
dm_bargraph6.currentY = dm_bargraph6.bargraphBottom - dm_bargraph6.sizeY;
dm_bargraph6.bargraphBottom = 188;
dm_bargraph6.interval = 20;
dm_bargraph6.bargraphSpeed = 1;

// Bargraph 7
dm_bargraph7.sizeX = 23;
dm_bargraph7.sizeY = 5;
dm_bargraph7.maxX = 23;
dm_bargraph7.maxY = 95;
dm_bargraph7.currentX = 240;
dm_bargraph7.currentY = dm_bargraph7.bargraphBottom - dm_bargraph7.sizeY;
dm_bargraph7.bargraphBottom = 188;
dm_bargraph7.interval = 20;
dm_bargraph7.bargraphSpeed = 1;

// Bargraph 8
dm_bargraph8.sizeX = 23;
dm_bargraph8.sizeY = 5;
dm_bargraph8.maxX = 23;
dm_bargraph8.maxY = 95;
dm_bargraph8.currentX = 265;
dm_bargraph8.currentY = dm_bargraph8.bargraphBottom - dm_bargraph8.sizeY;
dm_bargraph8.bargraphBottom = 188;
dm_bargraph8.interval = 20;
dm_bargraph8.bargraphSpeed = 1;

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
    DM_Bargraph1();
    DM_Bargraph2();
    DM_Bargraph3();
    DM_Bargraph4();
    DM_Bargraph5();
    DM_Bargraph6();
    DM_Bargraph7();
    DM_Bargraph8();
    
  }
   
}

void DM_Bargraph1(){

  if (CheckTime(currentMillis, dm_bargraph1.previousMillis, dm_bargraph1.interval)){
    if (dm_bargraph1.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph1.newY = random(dm_bargraph1.minY, (dm_bargraph1.maxY));

      dm_bargraph1.sCounter = 1;   
    }

    if (dm_bargraph1.newY >= dm_bargraph1.sizeY) {
      // Increase the bargraph size
      dm_bargraph1.sizeY = dm_bargraph1.sizeY + dm_bargraph1.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph1.currentY = dm_bargraph1.bargraphBottom - dm_bargraph1.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph1.sizeX, dm_bargraph1.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph1.currentX, dm_bargraph1.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph1.sizeY >= dm_bargraph1.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph1.sCounter = 0;
      }       
    }
    
    if (dm_bargraph1.newY < dm_bargraph1.sizeY){      
      // Decrease the bargraph size
      dm_bargraph1.sizeY = dm_bargraph1.sizeY - dm_bargraph1.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph1.maxX, dm_bargraph1.maxY - dm_bargraph1.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph1.currentX, dm_bargraph1.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph1.sizeY <= dm_bargraph1.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph1.sCounter = 0;
        }
    }    

    dm_bargraph1.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph2(){

  if (CheckTime(currentMillis, dm_bargraph2.previousMillis, dm_bargraph2.interval)){
    if (dm_bargraph2.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph2.newY = random(dm_bargraph2.minY, (dm_bargraph2.maxY));

      dm_bargraph2.sCounter = 1;   
    }

    if (dm_bargraph2.newY >= dm_bargraph2.sizeY) {
      // Increase the bargraph size
      dm_bargraph2.sizeY = dm_bargraph2.sizeY + dm_bargraph2.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph2.currentY = dm_bargraph2.bargraphBottom - dm_bargraph2.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph2.sizeX, dm_bargraph2.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph2.currentX, dm_bargraph2.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph2.sizeY >= dm_bargraph2.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph2.sCounter = 0;
      }       
    }
    
    if (dm_bargraph2.newY < dm_bargraph2.sizeY){      
      // Decrease the bargraph size
      dm_bargraph2.sizeY = dm_bargraph2.sizeY - dm_bargraph2.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph2.maxX, dm_bargraph2.maxY - dm_bargraph2.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph2.currentX, dm_bargraph2.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph2.sizeY <= dm_bargraph2.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph2.sCounter = 0;
        }
    }    

    dm_bargraph2.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph3(){

  if (CheckTime(currentMillis, dm_bargraph3.previousMillis, dm_bargraph3.interval)){
    if (dm_bargraph3.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph3.newY = random(dm_bargraph3.minY, (dm_bargraph3.maxY));

      dm_bargraph3.sCounter = 1;   
    }

    if (dm_bargraph3.newY >= dm_bargraph3.sizeY) {
      // Increase the bargraph size
      dm_bargraph3.sizeY = dm_bargraph3.sizeY + dm_bargraph3.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph3.currentY = dm_bargraph3.bargraphBottom - dm_bargraph3.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph3.sizeX, dm_bargraph3.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph3.currentX, dm_bargraph3.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph3.sizeY >= dm_bargraph3.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph3.sCounter = 0;
      }       
    }
    
    if (dm_bargraph3.newY < dm_bargraph3.sizeY){      
      // Decrease the bargraph size
      dm_bargraph3.sizeY = dm_bargraph3.sizeY - dm_bargraph3.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph3.maxX, dm_bargraph3.maxY - dm_bargraph3.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph3.currentX, dm_bargraph3.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph3.sizeY <= dm_bargraph3.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph3.sCounter = 0;
        }
    }    

    dm_bargraph3.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph4(){

  if (CheckTime(currentMillis, dm_bargraph4.previousMillis, dm_bargraph4.interval)){
    if (dm_bargraph4.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph4.newY = random(dm_bargraph4.minY, (dm_bargraph4.maxY));

      dm_bargraph4.sCounter = 1;   
    }

    if (dm_bargraph4.newY >= dm_bargraph4.sizeY) {
      // Increase the bargraph size
      dm_bargraph4.sizeY = dm_bargraph4.sizeY + dm_bargraph4.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph4.currentY = dm_bargraph4.bargraphBottom - dm_bargraph4.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph4.sizeX, dm_bargraph4.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph4.currentX, dm_bargraph4.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph4.sizeY >= dm_bargraph4.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph4.sCounter = 0;
      }       
    }
    
    if (dm_bargraph4.newY < dm_bargraph4.sizeY){      
      // Decrease the bargraph size
      dm_bargraph4.sizeY = dm_bargraph4.sizeY - dm_bargraph4.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph4.maxX, dm_bargraph4.maxY - dm_bargraph4.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph4.currentX, dm_bargraph4.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph4.sizeY <= dm_bargraph4.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph4.sCounter = 0;
        }
    }    

    dm_bargraph4.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph5(){

  if (CheckTime(currentMillis, dm_bargraph5.previousMillis, dm_bargraph5.interval)){
    if (dm_bargraph5.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph5.newY = random(dm_bargraph5.minY, (dm_bargraph5.maxY));

      dm_bargraph5.sCounter = 1;   
    }

    if (dm_bargraph5.newY >= dm_bargraph5.sizeY) {
      // Increase the bargraph size
      dm_bargraph5.sizeY = dm_bargraph5.sizeY + dm_bargraph5.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph5.currentY = dm_bargraph5.bargraphBottom - dm_bargraph5.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph5.sizeX, dm_bargraph5.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph5.currentX, dm_bargraph5.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph5.sizeY >= dm_bargraph5.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph5.sCounter = 0;
      }       
    }
    
    if (dm_bargraph5.newY < dm_bargraph5.sizeY){      
      // Decrease the bargraph size
      dm_bargraph5.sizeY = dm_bargraph5.sizeY - dm_bargraph5.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph5.maxX, dm_bargraph5.maxY - dm_bargraph5.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph5.currentX, dm_bargraph5.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph5.sizeY <= dm_bargraph5.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph5.sCounter = 0;
        }
    }    

    dm_bargraph5.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph6(){

  if (CheckTime(currentMillis, dm_bargraph6.previousMillis, dm_bargraph6.interval)){
    if (dm_bargraph6.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph6.newY = random(dm_bargraph6.minY, (dm_bargraph6.maxY));

      dm_bargraph6.sCounter = 1;   
    }

    if (dm_bargraph6.newY >= dm_bargraph6.sizeY) {
      // Increase the bargraph size
      dm_bargraph6.sizeY = dm_bargraph6.sizeY + dm_bargraph6.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph6.currentY = dm_bargraph6.bargraphBottom - dm_bargraph6.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph6.sizeX, dm_bargraph6.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph6.currentX, dm_bargraph6.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph6.sizeY >= dm_bargraph6.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph6.sCounter = 0;
      }       
    }
    
    if (dm_bargraph6.newY < dm_bargraph6.sizeY){      
      // Decrease the bargraph size
      dm_bargraph6.sizeY = dm_bargraph6.sizeY - dm_bargraph6.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph6.maxX, dm_bargraph6.maxY - dm_bargraph6.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph6.currentX, dm_bargraph6.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph6.sizeY <= dm_bargraph6.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph6.sCounter = 0;
        }
    }    

    dm_bargraph6.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph7(){

  if (CheckTime(currentMillis, dm_bargraph7.previousMillis, dm_bargraph7.interval)){
    if (dm_bargraph7.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph7.newY = random(dm_bargraph7.minY, (dm_bargraph7.maxY));

      dm_bargraph7.sCounter = 1;   
    }

    if (dm_bargraph7.newY >= dm_bargraph7.sizeY) {
      // Increase the bargraph size
      dm_bargraph7.sizeY = dm_bargraph7.sizeY + dm_bargraph7.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph7.currentY = dm_bargraph7.bargraphBottom - dm_bargraph7.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph7.sizeX, dm_bargraph7.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph7.currentX, dm_bargraph7.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph7.sizeY >= dm_bargraph7.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph7.sCounter = 0;
      }       
    }
    
    if (dm_bargraph7.newY < dm_bargraph7.sizeY){      
      // Decrease the bargraph size
      dm_bargraph7.sizeY = dm_bargraph7.sizeY - dm_bargraph7.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph7.maxX, dm_bargraph7.maxY - dm_bargraph7.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph7.currentX, dm_bargraph7.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph7.sizeY <= dm_bargraph7.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph7.sCounter = 0;
        }
    }    

    dm_bargraph7.previousMillis = currentMillis;    
  }
  
}

void DM_Bargraph8(){

  if (CheckTime(currentMillis, dm_bargraph8.previousMillis, dm_bargraph8.interval)){
    if (dm_bargraph8.sCounter == 0) {
      // Generate the next value for the bargraph, then flag the sequence counter
      dm_bargraph8.newY = random(dm_bargraph8.minY, (dm_bargraph8.maxY));

      dm_bargraph8.sCounter = 1;   
    }

    if (dm_bargraph8.newY >= dm_bargraph8.sizeY) {
      // Increase the bargraph size
      dm_bargraph8.sizeY = dm_bargraph8.sizeY + dm_bargraph8.bargraphSpeed;
      
      // Calculate the new position of the bar
      dm_bargraph8.currentY = dm_bargraph8.bargraphBottom - dm_bargraph8.sizeY;

      // Draw the new bargraph
      dm_spr_barGraph.createSprite(dm_bargraph8.sizeX, dm_bargraph8.sizeY);
      dm_spr_barGraph.fillSprite(TFT_RED);
      dm_spr_barGraph.pushSprite(dm_bargraph8.currentX, dm_bargraph8.currentY);
      dm_spr_barGraph.deleteSprite();

      if (dm_bargraph8.sizeY >= dm_bargraph8.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph8.sCounter = 0;
      }       
    }
    
    if (dm_bargraph8.newY < dm_bargraph8.sizeY){      
      // Decrease the bargraph size
      dm_bargraph8.sizeY = dm_bargraph8.sizeY - dm_bargraph8.bargraphSpeed;

      // To shrink the bar, we'll need to draw a black sprite over the top part of the bar.
            
      // Draw the black sprite
      dm_bg_barGraph.createSprite(dm_bargraph8.maxX, dm_bargraph8.maxY - dm_bargraph8.sizeY);
      dm_bg_barGraph.fillSprite(TFT_BLACK);
      dm_bg_barGraph.pushSprite(dm_bargraph8.currentX, dm_bargraph8.maxY - 2);
      dm_bg_barGraph.deleteSprite();
     
      
      if (dm_bargraph8.sizeY <= dm_bargraph8.newY){
      // Once the bargraph meets the new value, reset the sequence counter so a new value can be generated
      dm_bargraph8.sCounter = 0;
        }
    }    

    dm_bargraph8.previousMillis = currentMillis;    
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
