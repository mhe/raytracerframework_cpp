//
//  Framework for a raytracer
//  File: object.h
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

#ifndef OBJECT_H_AXKLE0OF
#define OBJECT_H_AXKLE0OF

#include "triple.h"
#include "light.h"

class Material;

class Object {
public:
	Material *material;

	virtual ~Object()
		{ }

	virtual bool intersect(const Ray &ray, double *t) = 0;
	virtual Vector normal(const Point &hit) = 0;
};

#endif /* end of include guard: OBJECT_H_AXKLE0OF */
