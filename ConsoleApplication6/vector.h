#include <iostream>

class vector{
public:
	double x;
	double y;
	double z;
	double GetLength();
};

vector operator+ (vector a, vector b);
vector operator* (double d, vector v);
vector operator* (vector a, vector b);
std::ostream& operator<< (std::ostream&, vector vec);
