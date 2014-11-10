#ifndef PinballTable_h
#define PinballTable_h

#include <string>
#include <vector>
#include "Triangle.h"
#include "Vector.h"

class PinballTable
{
public:
    
    //make up a random 'pinball table' from hand-place triangles
    PinballTable();
    
    //read the table description from a blender output file
    PinballTable(std::string Filename);
    
    //compute the normal force the
    Vector Collide(const Ball& projuctile) const;
    
    //draw the table and the ball
    void render();
    
private:
    std::vector<Triangle> description;
    Ball ball;
};

#endif /* defined(PinballTable_h) */
