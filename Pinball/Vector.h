#ifndef Vector_h
#define Vector_h

#include <iostream>

class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);
    
	double getLength();
    
	double x;
	double y;
    double z;
};

Vector operator+ (Vector a, Vector b);
Vector operator- (Vector a, Vector b);
Vector operator* (double d, Vector v);
Vector operator* (Vector a, double b);
double inproduct (Vector a, Vector b);
Vector crossproduct (Vector a, Vector b);
std::ostream& operator<< (std::ostream&, Vector vec);

#endif
