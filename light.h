/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    light.h
 *   CONTENT: Light declaration
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: light.h,v 1.2 2001/11/01 16:47:46 bert Exp bert $
 *
 *****************************************************************************/

#ifndef LIGHT_H_PG2BAJRA
#define LIGHT_H_PG2BAJRA

#include <iostream>
#include "triple.h"

class Light
{
public:
	Light(Point pos,Color c) : position(pos), color(c)
	 { }
	 
	Point position;
	Color color;
};

class Ray
{
public:
	Point O;
	Vector D;

	Ray(const Point &from, const Vector &dir)
		: O(from), D(dir)
		{ }

	Point at(double t) const
		{ return O + t*D; }

};

#endif /* end of include guard: LIGHT_H_PG2BAJRA */
