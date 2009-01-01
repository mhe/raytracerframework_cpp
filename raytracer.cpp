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
	return scene->trace(ray);
}

/*
 * Raytrace Raytracer into image
 */

void Raytracer::trace(Image &img)
{
	scene->render(img);
}

/*
 * Read a scene from file
 */

bool Raytracer::read(istream& is)
{
  Material *mat = 0;
  Triple eye;
  scene = new Scene();
  while (is) {
    char ch = 0;
    is >> comment >> ch >> word >> comment;
    ch = toupper(ch);
    cerr << ch;
    switch (ch) {
      case 'E': // Eye
	is >> eye;
	scene->setEye(eye);
	break;
      case 'M': // Material
	mat = new Material;
	is >> *mat;
	break;
      case 'L': // Light
	  Light *light = new Light;
	  is >> *light;
	  //lights[light_count++] = light;
	  scene->addLight(light);
	break;
      case 'S': // Sphere
	  Sphere *sph = new Sphere;
	  is >> *sph;
	  sph->material = mat;
  	  scene->addObject(sph);
	break;
      default:
	cerr << "?" << endl;
	return false;
    }
  }
  cerr << endl;
  return true;
}


