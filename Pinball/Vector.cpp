#include <iostream>
#include <cmath>

#include "Vector.h"

Vector::Vector() : x(0), y(0), z(0)
{
}

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z)
{
}

double Vector::getLength() const
{
	double c;
    c = std::sqrt(x*x + y*y + z*z);
	return c;
	
}

Vector operator+(Vector a, Vector b)
{
	Vector r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	return r;
}



Vector operator-(Vector a, Vector b)
{
	Vector r;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	return r;
}

Vector operator*(double d, Vector v)
{
	Vector r;
	r.x = d * v.x;
	r.y = d * v.y;
	r.z = d * v.z;
	return r;
}

Vector operator*(Vector v, double d)
{
	return d * v;
}

double inproduct(Vector a, Vector b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vector crossproduct(Vector a, Vector b)
{
    Vector result;
    result.x = a.y*b.z - a.z*b.y;
    result.y = a.z*b.x - a.x*b.z;
    result.z = a.x*b.y - a.y*b.x;
    return result;
}

std::ostream& operator<<(std::ostream& out, Vector vec)
{
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
	return out;
}
