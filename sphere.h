//
//  Framework for a raytracer
//  File: sphere.h
//
//  Created for the Computer Science course "Introduction Computer Graphics"
//  taught at the University of Groningen by Tobias Isenberg.
//
//  Author: Maarten Everts
//
//  This framework is inspired by and uses code of the raytracer framework of 
//  Bert Freudenberg that can be found at
//  http://isgwww.cs.uni-magdeburg.de/graphik/lehre/cg2/projekt/rtprojekt.html 
//

#ifndef SPHERE_H_115209AE
#define SPHERE_H_115209AE

#include "object.h"

class Sphere : public Object
{
public:
	Sphere()
		{ }
	Sphere(Point position,double r)
		{ this->position = position; this->r = r; }

	virtual bool intersect(const Ray &ray, double *t);
	virtual Vector normal(const Point &P);
	
	Point position;
	double r;	
};

#endif /* end of include guard: SPHERE_H_115209AE */
