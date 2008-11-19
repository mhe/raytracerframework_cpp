/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    material.h
 *   CONTENT: Material declaration
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: material.h,v 1.3 2002/11/20 20:00:25 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __MATERIAL_H
#define __MATERIAL_H

#include <iostream>
#include "triple.h"

class Material
{
public:
  Color color;        // base color
  float ambient;      // ambient intensity
  float diffuse;      // diffuse intensity
  float specular;     // specular intensity 
  float phong;        // exponent for specular highlight size

  Material()
    { }

  friend istream& operator>>(istream &is, Material &m);
};

#endif
