#include "Collide.h"
#include "Ball.h"
#include "Triangle.h"
#include "Vector.h"

// VERY IMPORTANT WEBSITE    http://geomalgorithms.com/a06-_intersect-2.html   
// Contains a description and example code for collision detection

// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.


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


	u = t.getCorner(1) - t.getCorner(0);
	v = t.getCorner(2) - t.getCorner(0);
	n = crossproduct(u, v);
	if (n.x == 0 && n.y == 0 && n.z == 0)			    // triangle is degenerate
		return -1;									// do not deal with this case

	q0 = ball.getCenter() - ball.getRadius() * n * (1 / n.getLength()); 
	q1 = ball.getCenter() + ball.getRadius() * n * (1 / n.getLength());
	dir = q0 - q1;
	w0 = q0 - t.getCorner(0);
	a = -inproduct(n, w0);
	b = inproduct(n, dir);
	if (fabs(b) < SMALL_NUM)						// ball vector is parallel to the triangle. This should never happen, as 
	{
		if (a == 0)
			return 2;
		else return 0;
	}
	// get intersect point of ray with triangle plane
	r = a / b;
	if (r < 0.0 || r > 1.0)                    
		return 0;                   // => no intersect



	Vector I = q0 + r * dir;            // intersect point of ball and triangle

	// is I inside T?
	float    uu, uv, vv, wu, wv, D;
	uu = dot(u, u);
	uv = dot(u, v);
	vv = dot(v, v);
	w = I - t.getCorner(0);
	wu = dot(w, u);
	wv = dot(w, v);
	D = uv * uv - uu * vv;

	// get and test parametric coords
	float f, g;
	f = (uv * wv - vv * wu) / D;
	if (f < 0.0 || f > 1.0)			// I is outside T
		return 0;
	g = (uv * wu - uu * wv) / D;
	if (g < 0.0 || (f + g) > 1.0)	// I is outside T
		return 0;

	return 1;						// I is in T

	float force;
	float elasticity = 1000;
	force = elasticity * (I - q0).getLength() * n / n.getLength;


}