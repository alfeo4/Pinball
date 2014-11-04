#include <iostream>
#include <cmath>

#include "Vector.h"

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

double Vector::getLength()
{
	double c;
    c = std::sqrt(x*x + y*y + z*z);
	return c;
	
}


std::ostream& operator<<(std::ostream& out, Vector vec)
{
	out << "(" << vec.x << " , " << vec.y << " , " << vec.z << ")";
	return out;
}

/*


int main(int argc, char** argv)

	{
		vector v;
		v.x = 7;
		v.y = 6;
		v.z = 5;

		vector a;
		a.x = 1;
		a.y = 2;
		a.z = 3;

		vector b;
		b.x = 2;
		b.y = 4;
		b.z = 6;

		double d = 5;

		vector c = a - b;


		


		std::cout << GetLength(c) << "," << c << std::endl;
		
	}

	*/

