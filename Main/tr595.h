// Animation Element

class Anim {
   
  public:
    int sizeX, sizeY;
    int minX, maxX, minY, maxY;
    int currentX, currentY, oldX, oldY;
    bool reverse = false;
    unsigned long previousMillis = 0;
    int interval;
  
};
