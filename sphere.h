/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    sphere.h
 *   CONTENT: Sphere declaration
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: sphere.h,v 1.2 2002/11/20 20:23:28 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __SPHERE_H
#define __SPHERE_H

#include "object.h"

class Sphere : public Object
{
protected:
	Point position;
	double r;
public:

	Sphere(Point position,double r)
		{ this->position = position; this->r = r; }

	virtual bool intersect(const Ray &ray, double *t);
	virtual Vector normal(const Point &P);
};

#endif
