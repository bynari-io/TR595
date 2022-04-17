// Animation Element

class Anim {
   
  public:
    int sizeX, sizeY;
    int minX, maxX, minY, maxY;
    int currentX, currentY, oldX, oldY, newX, newY;
    bool reverse = false;
    unsigned long previousMillis = 0;
    int interval;
    bool isVisible = true;
    int sCounter = 0;
    int bargraphBottom;
    int bargraphSpeed;
    
  
};

// Check Interval

bool CheckTime(unsigned long currentMillis, unsigned long previousMillis, int interval){

  if ((currentMillis - previousMillis) > interval){
    return true;
  }

  return false;
  
}
