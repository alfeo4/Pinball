#include "Collide.h"


// VERY IMPORTANT WEBSITE    http://geomalgorithms.com/a06-_intersect-2.html   
// Contains a description and example code for collision detection


// First, see whether the ball projects onto the wall

int IntersectBallTriangle(Ball, Triangle, Point* Intersect)
{
	#define SMALL_NUM   0.00000001 // anything that avoids division overflow
	Vector    u, v, n;              // triangle vectors (u is V0->V1, v is V0->V2, n is the normal vector
	Vector    dir, w0, w;           // "ball vectors", dir is twice the radius of the ball (a vector pointing towards the triangle 
									// in the direction of -n), w0 is the shortest distance between the bottom of the ball and V0, 
									// w is the vector between V0 and the intersection point
	float     r, a, b;              // additional parameters

	u =
	v =
	n = crossproduct(u, v);
	if (n == (0,0,0)			    // triangle is degenerate
		return -1;                  // do not deal with this case

	dir =
	w0 =
	a = -inproduct(n, w0);
	b = inproduct(n, dir);
	if fabs(b) < SM

}