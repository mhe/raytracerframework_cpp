//
//  Framework for a raytracer
//  File: sphere.cpp
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

#include "sphere.h"
#include <iostream>
#include <math.h>

/************************** Sphere **********************************/

bool Sphere::intersect(const Ray &ray, double *t)
{
	/****************************************************
	* RT1.1: INTERSECTION CALCULATION
	*
	* Given: ray, position, r
	* Sought: intersects? if true: *t
	* 
	* Insert calculation of ray/sphere intersection here. 
	*
	* You have the sphere's center (C) and radius (r) as well as
	* the ray's origin (ray.O) and direction (ray.D).
	*
	* If the ray does not intersect the sphere, return false.
	* Otherwise, return true and place the distance of the
	* intersection point from the ray origin in *t (see example).
	****************************************************/

	// place holder for actual intersection calculation

	Vector OC = (position - ray.O).normalized();
	if (OC.dot(ray.D) > 0.999) {
		*t = 1000;
		return true;
	}

	return false;
}


Vector Sphere::normal(const Point &P)
{
	/****************************************************
	* RT1.2: NORMAL CALCULATION
	*
	* Given: P, C, r
	* Sought: N
	* 
	* Insert calculation of the sphere's normal at point P here.
	****************************************************/

	Vector N /* = ... */;

	return N;
}

