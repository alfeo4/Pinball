#include "Triangle.h"

Triangle::Triangle(Vector a, Vector b, Vector c) : corners({a, b, c})
{
}

Vector Triangle::getCorner(size_t index)
{
    return corners[index];
}


