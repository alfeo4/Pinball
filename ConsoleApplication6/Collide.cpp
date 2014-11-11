#include "Collide.h"
#include "Ball.h"
#include "Triangle.h"
#include "Vector.h"

// VERY IMPORTANT WEBSITE    http://geomalgorithms.com/a06-_intersect-2.html   
// Contains a description and example code for collision detection


// First, see whether the ball projects onto the wall

int IntersectBallTriangle(Ball ball, Triangle t, Vector* Intersect)
{
	#define SMALL_NUM   0.00000001	// avoids division overflow
	Vector    u, v, n;              // triangle vectors (u is V0->V1, v is V0->V2, n is the normal vector
	Vector    q0 , q1, dir, w0, w;  // q0 and q1 will contain the points on the ball's surface that is closest to (q0) and farthest from (q1) the triangle;
									// dir is twice the radius of the ball (a vector pointing towards the triangle 
									// in the direction of -n); w0 is the shortest distance between the bottom of the ball and V0;
									// w is the vector between V0 and the intersection point
	float     r, a, b;              // additional parameters

	u = Triangle(b) - Triangle(a);
	v = Triangle(c) - Triangle(a);
	n = crossproduct(u, v);
	if (n == (0,0,0))			    // triangle is degenerate
		return -1;                  // do not deal with this case

	q0 = getCenter(Ball) - getRadius(Ball) * n / getLength(n);
	q1 = getCenter(Ball) + getRadius(Ball) * n / getLength(n);
	dir = q0 - q1;
	w0 = q0 - Triangle(a);
	a = -inproduct(n, w0);
	b = inproduct(n, dir);
	if fabs(b) < SMALL_NUM			//
	{
		if (a == 0)
			return 2;
		else return 0;
	}


}