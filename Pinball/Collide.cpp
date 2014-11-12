#include "Collide.h"
#include "Ball.h"
#include "Triangle.h"
#include "Vector.h"

#include <cmath>
#include <iostream>

// VERY IMPORTANT WEBSITE    http://geomalgorithms.com/a06-_intersect-2.html   
// Contains a description and example code for collision detection

// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.


// First, see whether the ball projects onto the wall

Vector IntersectBallTriangle(Ball ball, Triangle t, Vector* Intersect)
{
    const double small = 1e-12;
    const double large  = 1e3;
	Vector    u, v, normal;              // triangle vectors (u is V0->V1, v is V0->V2, n is the normal vector
	Vector    q0 , q1, dir, w0, w;  // q0 and q1 will contain the points on the ball's surface that is closest to (q0) and farthest from (q1) the triangle;
									// dir is twice the radius of the ball (a vector pointing towards the triangle 
									// in the direction of -n); w0 is the shortest distance between the bottom of the ball and V0;
									// w is the vector between V0 and the intersection point
	float     r, a, b;              // additional parameters


	u = t.getCorner(1) - t.getCorner(0);
	v = t.getCorner(2) - t.getCorner(0);
	normal = crossproduct(u, v);
	if (normal.getLength() < small)			    // triangle is degenerate
    {
        std::cerr << "degenerate triangle detected, fix your blender" << std::endl;
        exit(1);
    }

    normal = normal / normal.getLength();
    
	q0 = ball.getCenter() - ball.getRadius() * normal;
	q1 = ball.getCenter() + ball.getRadius() * normal;
	dir = q0 - q1;
	w0 = q0 - t.getCorner(0);
	a = -inproduct(normal, w0);
	b = inproduct(normal, dir);
    // ball vector is parallel to the triangle. This should never happen, as ortogonal lines are never parallel
    if (std::abs(b) < small)						
	{
        std::cerr << "degenerate ball detected, fix" <<std::endl;
        exit(1);
	}
	// get intersect point of ray with triangle plane
	r = a / b;
	if (r < 0.0 || r > 1.0)
    {
        return {0, 0, 0};                   // => no intersect
    }
    
    // intersection between ball radius and (extended) plane of triangle
	Vector intersect = q0 + r * dir;
    
	// is I inside T?
	float    uu, uv, vv, wu, wv, D;
	uu = inproduct(u, u);
	uv = inproduct(u, v);
	vv = inproduct(v, v);
	w = intersect - t.getCorner(0);
	wu = inproduct(w, u);
	wv = inproduct(w, v);
	D = uv * uv - uu * vv;

	// get and test parametric coords
	float f, g;
	f = (uv * wv - vv * wu) / D;
	if (f < 0.0 || f > 1.0)			// I is outside T
    {
        return {0, 0, 0};
    }
	g = (uv * wu - uu * wv) / D;
	if (g < 0.0 || (f + g) > 1.0)	// I is outside T
    {
        return {0, 0, 0};
    }

	Vector force;
	float elasticity = large;
	force = elasticity * (w0 - w);

    return force;
}