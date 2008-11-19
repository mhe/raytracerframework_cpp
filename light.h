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

#ifndef __LIGHT_H
#define __LIGHT_H

#include <iostream>
#include "triple.h"

class Light
{
public:
  Point P;
  Color color;

  friend istream& operator>>(istream &is, Light &l);
};

class Ray
{
public:
  Point O;
  Vector D;

  // Ray(const Point &from, const Vector &dir)
  //   : O(from), D(dir)
  //   { }

  Ray(const Point &from, const Point &to)
    : O(from), D(to - from)
    { D.normalize(); }

  Point at(double t) const
    { return O + t*D; }

};


#endif
