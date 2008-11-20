/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    raytracer.cpp
 *   CONTENT: Raytracing algorithm implmentation, plus scene reading
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: raytracer.cpp,v 1.2 2000/05/15 10:18:49 bert Exp bert $
 *
 *
 *****************************************************************************/

#include "raytracer.h"
#include "object.h"
#include "sphere.h"
#include "material.h"
#include "light.h"
#include "image.h"
#include <ctype.h>
#include <iostream>

/*
 * Trace one ray, answer color
 */

Color Raytracer::trace(const Ray &ray)
{
  // Find hit object and distance
  double t, min_t = 0.0;
  Object *obj = 0;
  for (int i = 0; i < obj_count; ++i)
    if (objs[i]->intersect(ray, &t) && (!obj || t < min_t)) {
      min_t = t;
      obj = objs[i];
    }
  if (!obj) return Color(0.0, 0.0, 0.0);

  Material *material = obj->material;            //the hit objects material
  Point hit = ray.at(min_t);                     //the hit point
  Vector N = obj->normal(hit);                   //the normal
  Vector V = -ray.D;                             //the view vector


  /****************************************************
   * RT1.3: LIGHTING CALCULATION
   * 
   * Insert calculation of color here (PHONG model).
   *
   * Given: material, hit, N, V, lights[]
   * Sought: color
   *
   * Hints: (see vector.h)
   *        Vector*Vector      dot product
   *        Vector+Vector      vector sum
   *        Vector-Vector      vector difference
   *        Point-Point        yields vector
   *        Vector.normalize() normalizes vector, returns length
   *        float*Color        scales each color component (r,g,b)
   *        Color*Color        dito
   *        pow(a,b)           a to the power of b
   ****************************************************/


  Color color = material->color;                  // place holder

  return color;
}

/*
 * Raytrace Raytracer into image
 */

void Raytracer::trace(Image &img)
{
  int w = img.width();
  int h = img.height();
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      Point pixel(x, h-1- y, 0);
      Ray ray(eye, (pixel-eye).normalized());
      Color col = trace(ray);
      col.clamp();
      img(x,y) = col;
    }
  }
}

/*
 * Read a scene from file
 */

bool Raytracer::read(istream& is)
{
  Material *mat = 0;

  while (is) {
    char ch = 0;
    is >> comment >> ch >> word >> comment;
    ch = toupper(ch);
    cerr << ch;
    switch (ch) {
      case 'E': // Eye
	is >> eye;
	break;
      case 'M': // Material
	mat = new Material;
	is >> *mat;
	break;
      case 'L': // Light
	if (light_count < MAXLIGHT) {
	  Light *light = new Light;
	  is >> *light;
	  lights[light_count++] = light;
	} else
	  cerr << "\nMore than " << MAXLIGHT << " Lights!" << endl;
	break;
      case 'S': // Sphere
	if (obj_count < MAXOBJ) {
	  Sphere *sph = new Sphere;
	  is >> *sph;
	  sph->material = mat;
	  objs[obj_count++] = sph;
	} else
	  cerr << "\nMore than " << MAXOBJ << " Objects!" << endl;
	break;
      default:
	cerr << "?" << endl;
	return false;
    }
  }
  cerr << endl;
  return true;
}


