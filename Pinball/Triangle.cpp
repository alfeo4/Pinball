#include "Triangle.h"

#include <cmath>

Triangle::Triangle(Vector a, Vector b, Vector c) : corners({a, b, c})
{
}

Vector Triangle::getCorner(size_t index) const
{
    return corners[index];
}



// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.
// (website: http://geomalgorithms.com/a06-_intersect-2.html )

//with modifications for colliding ball and triangle instead of lines and triangle
Vector Triangle::Collide(const Ball &projectile) const{
    
    const double small = 1e-12;
    const double large  = -1e6;
    Vector    u, v, normal;              // triangle vectors (u is V0->V1, v is V0->V2, n is the normal vector
    Vector    q0 , q1, dir, w0, w;  // q0 and q1 will contain the points on the ball's surface that is closest to (q0) and farthest from (q1) the triangle;
    // dir is twice the radius of the ball (a vector pointing towards the triangle
    // in the direction of -n); w0 is the shortest distance between the bottom of the ball and V0;
    // w is the vector between V0 and the intersection point
    float     r, a, b;              // additional parameters
    
    u = getCorner(0) - getCorner(1);
    v = getCorner(0) - getCorner(2);
    normal = crossproduct(u, v);
    if (normal.getLength() < small)			    // triangle is degenerate
    {
        std::cerr << "degenerate triangle detected, fix your blender" << std::endl;
        exit(1);
    }
    
    normal = normal / normal.getLength();
    
    q0 = projectile.getCenter() + projectile.getRadius() * normal;
    q1 = projectile.getCenter() - projectile.getRadius() * normal;
    dir = q0 - q1;
    w0 = getCorner(0) - q0;
    a = -inproduct(normal, w0);
    b = 2. * projectile.getRadius();
    // ball vector is parallel to the triangle. This should never happen, as ortogonal lines are never parallel
    if (std::abs(b) < small)
    {
        std::cerr << "degenerate ball detected, fix" <<std::endl;
        exit(1);
    }
    // get intersect point of ray with triangle plane
    r = a / b;
    //r<0 means ball is completely above the plane; r>1 means ball is completely below the plane
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
    w = getCorner(0) - intersect;
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
    force = elasticity * (r * dir);
    
    return force;
}
