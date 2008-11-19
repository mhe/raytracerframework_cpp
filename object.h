/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    object.h
 *   CONTENT: Object declaration
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: object.h,v 1.1 2000/04/10 10:21:17 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __OBJECT_H
#define __OBJECT_H

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

#endif
