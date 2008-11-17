/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    sphere.cpp
 *   CONTENT: Sphere implementation
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: sphere.cpp,v 1.2 2000/05/15 10:18:26 bert Exp bert $
 *
 *****************************************************************************/

#include "sphere.h"
#include "misc.h"
#include <iostream>
#include <math.h>

/************************** Sphere **********************************/

bool Sphere::intersect(const Ray &ray, double *t)
{
  /****************************************************
   * RT1.1: INTERSECTION CALCULATION
   *
   * Given: ray, C, r
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

  Vector OC = (C - ray.O).normalized();
  if (OC * ray.D > 0.999) {
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


istream& operator>>(istream &is, Sphere &s)
{
  is >> s.C >> comment
     >> s.r >> comment;
  return is;
}

