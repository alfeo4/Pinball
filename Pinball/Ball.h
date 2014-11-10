#ifndef BALL_H
#define BALL_H

#include "Vector.h"

class Ball
{
public:
    //Make a ball
    Ball(Vector center, double radius, Vector velocity);
    
    Vector getCenter() const;
    double getRadius() const;
    
    //Move a ball a bit
    void doPhysics();
    
private:
    Vector center;
    Vector velocity;
    double radius;
};


#endif /* defined(Ball_h) */
