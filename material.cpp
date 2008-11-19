/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    material.cpp
 *   CONTENT: Non-inlined material functions
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: material.cpp,v 1.1 2000/04/10 10:21:17 bert Exp bert $
 *
 *****************************************************************************/

#include "material.h"
#include <iostream>
#include "misc.h"

istream& operator>>(istream &is, Material &m)
{
  is >> m.color >> comment
     >> m.ambient >> m.diffuse >> m.specular >> m.phong;
  return is;
}
