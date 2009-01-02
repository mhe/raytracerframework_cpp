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

#ifndef MATERIAL_H_TWMNT2EJ
#define MATERIAL_H_TWMNT2EJ

#include <iostream>
#include "triple.h"

class Material
{
public:
	Color color;        // base color
	float ka;           // ambient intensity
	float kd;           // diffuse intensity
	float ks;           // specular intensity 
	float n;            // exponent for specular highlight size

	Material()
		{ }
};

#endif /* end of include guard: MATERIAL_H_TWMNT2EJ */
