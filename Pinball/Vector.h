#include <iostream>

class Vector
{
public:
	double x;
	double y;
	double z;
	double getLength();
};

Vector operator+ (Vector a, Vector b);
Vector operator- (Vector a, Vector b);
Vector operator* (double d, Vector v);
Vector operator* (Vector a, double b);
std::ostream& operator<< (std::ostream&, Vector vec);
