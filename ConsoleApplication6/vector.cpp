#include <iostream>
#include <math.h>

#include "vector.h"

vector operator+(vector a, vector b) {
	vector r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	return r;
}



vector operator-(vector a, vector b) {
	vector r;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	return r;
}

vector operator*(double d, vector v) {
	vector r;
	r.x = d * v.x;
	r.y = d * v.y;
	r.z = d * v.z;
	return r;
}

vector operator*(vector v, double d) {
	return d * v;
}

double GetLength(vector a) {
	double c;
	c = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return c;
	
}


std::ostream& operator<<(std::ostream& out, vector vec)
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

