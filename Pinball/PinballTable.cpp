#include "PinballTable.h"
#include "Vector.h"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cassert>


PinballTable::PinballTable(std::string filename, const Ball& ball) : ball(ball)
{
    std::ifstream source{filename};
    
    char linetype;
    std::vector<Vector> vertices;
    std::string stringBuffer;
    std::stringstream buffer;
    
    while(!source.eof()){
    
        std::getline(source, stringBuffer);
        buffer.str(stringBuffer);
        buffer >> linetype;
        
        if(linetype == 'v')
        {
            double a, b, c;
            buffer >> a >> b >> c;
            Vector newVec = {a, b, c};
            vertices.push_back(std::move(newVec));
        }
        else if(linetype == 'f')
        {
            int a, b, c;
            buffer >> a >> b >> c;
            
            //panic and kill the program if this file contains nonsense
            assert(a<=vertices.size());
            assert(b<=vertices.size());
            assert(c<=vertices.size());
            
            //silly one based numbering means we have to subtract one
            const Vector& vA = vertices[a - 1];
            const Vector& vB = vertices[b - 1];
            const Vector& vC = vertices[c - 1];
            
            Triangle newTriangle = {vA, vB, vC};
            
            description.push_back(std::move(newTriangle));
        }
        
        buffer.clear();
    }
    
    //dont leak resources close stuff once you are done with them
    source.close();
}

void PinballTable::render(sf::RenderWindow& window, double scale) 
{
    //find a better place for this
    for(std::size_t i=0;i<2000;i++)
    {
        ball.doPhysics(*this);
    }
    
    sf::ConvexShape sfTriangle(3);
    sfTriangle.setFillColor(sf::Color::Green);
    Vector corner;
    sf::Vector2f sfCorner;
    sf::Vector2u offset = window.getSize() / 2u;
    
    for(Triangle t:description)
    {
        for(size_t i=0; i<3; ++i)
        {
            corner = t.getCorner(i);
            sfCorner.x = scale * corner.z + offset.x;
            sfCorner.y = - scale * corner.x + offset.y;//let y move up
            sfTriangle.setPoint(i, sfCorner);
        }
        window.draw(sfTriangle);
    }
    
    sf::CircleShape sfBall;
    Vector center = ball.getCenter();
    
    double radius = scale * ball.getRadius();
    
    sfBall.setPosition(scale * center.z + offset.x - radius, -scale * center.x + offset.y - radius);
    std::cout << "y: " << center.y << std::endl;
    
    sfBall.setRadius(radius);
    sfBall.setPointCount(31);
    sfBall.setFillColor(sf::Color::Red);
    
    window.draw(sfBall);
    
}

Vector PinballTable::Collide(const Ball &projectile) const
{
    Vector result{0, 0, 0};
    for(Triangle t:description)
    {
        result = result + t.Collide(projectile);
    }
    return result;
}