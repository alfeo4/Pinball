#ifndef PINBALLTABLE_H
#define PINBALLTABLE_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Triangle.h"
#include "Vector.h"

class PinballTable
{
public:
    
    //read the table description from a blender output file
    PinballTable(std::string Filename, const Ball& ball);
    
    //compute the normal force the
    Vector Collide(const Ball& projuctile) const;
    
    //draw the table and the ball
    void render(sf::RenderWindow&, double scale = 500.0) const;
    
private:
    std::vector<Triangle> description;
    Ball ball;
};

#endif /* defined(PinballTable_h) */
