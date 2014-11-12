#include "Ball.h"
#include "PinballTable.h"

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

void Ball::doPhysics(PinballTable table)
{
    const double dt=1e-5;
    Vector g{-1, 0, 0};
    Vector acceleration = table.Collide(*this) + g;
    velocity = velocity + dt * acceleration;
    center = center + dt * velocity;
}