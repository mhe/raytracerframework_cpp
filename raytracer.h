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
#include "light.h"
#include "scene.h"


class Raytracer {
private:
	Scene *scene;
public:
	Raytracer()
		{ }

	bool readScene(char* inputFilename);
	void renderToFile(char* outputFilename);
};

#endif
