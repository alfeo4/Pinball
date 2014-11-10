#ifndef Ball_h
#define Ball_h

#include "Vector.h"

class Ball
{
public:
    //Make a ball
    Ball(Vector center, double radius);
    
    //Move a ball a bit
    void doPhysics();
    
private:
    Vector center;
    double radius;
};


#endif /* defined(Ball_h) */
