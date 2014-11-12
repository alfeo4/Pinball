#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vector.h"
#include "Ball.h"
#include <array>

class Triangle
{
public:
    //Pass three corners to the triangle to create one
    Triangle(Vector a, Vector b, Vector c);
    
    Vector getCorner(size_t index) const;
    
    //Compute the force contribution of this triangle (is 0 when there is no collision)
    Vector Collide(const Ball& projectile) const;
    
private:
    std::array<Vector, 3> corners;
    
};

#endif
