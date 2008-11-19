/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    raytracer.h
 *   CONTENT: The raytracing algorithm, plus scene reading
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: raytracer.h,v 1.2 2001/11/01 16:47:46 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __RAYTRACER_H
#define __RAYTRACER_H

#include <iostream>
#include "triple.h"
#include "misc.h"
#include "light.h"

const int MAXOBJ      = 100;
const int MAXLIGHT    = 10;

class Object;
class Light;
class Image;

class Raytracer {
public:
  Point eye;
  Object* objs[MAXOBJ];
  int obj_count;
  Light* lights[MAXLIGHT];
  int light_count;

  Raytracer()
    : eye(0, 0, 0), obj_count(0), light_count(0)
  { }

  Color trace(const Ray &ray);
  void trace(Image &img);

  bool read(istream& is);
};

#endif
