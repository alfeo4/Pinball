#include "Ball.h"

Ball::Ball(Vector c, double d, Vector v) : center(c), radius(d), velocity(v)
{
}

double Ball::getRadius() const
{
    return radius;
}

Vector Ball::getCenter() const
{
    return center;
}