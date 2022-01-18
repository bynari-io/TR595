// Animation Element

class Anim {
   
  public:
    int sizeX, sizeY;
    int minX, maxX, minY, maxY;
    int currentX, currentY, oldX, oldY;
    bool reverse = false;
    unsigned long previousMillis = 0;
    int interval;
    bool isVisible = true;
    bool sequenceComplete = false;
    
  
};

// Check Interval

bool CheckTime(unsigned long currentMillis, unsigned long previousMillis, int interval){

  if ((currentMillis - previousMillis) > interval){
    return true;
  }

  return false;
  
}
