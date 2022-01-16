// Animation Element

class Anim {
   
  public:
    int sizeX, sizeY;
    int minX, maxX, minY, maxY;
    int currentX, currentY, oldX, oldY;
    bool reverse = false;
    bool visible = true;
    unsigned long previousMillis = 0;
    int interval;
    
  
};

// Check Interval

bool CheckTime(unsigned long currentMillis, unsigned long previousMillis, int interval){

  if ((currentMillis - previousMillis) > interval){
    return true;
  }

  return false;
  
}
