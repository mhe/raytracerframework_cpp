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

#ifndef RAYTRACER_H_6GQO67WK
#define RAYTRACER_H_6GQO67WK

#include <iostream>
#include "triple.h"
#include "light.h"
#include "scene.h"
#include "yaml/yaml.h"

class Raytracer {
private:
	Scene *scene;
	
	// Couple of private functions for parsing YAML nodes
	Material* parseMaterial(const YAML::Node& node);
	Object* parseObject(const YAML::Node& node);
	Light* parseLight(const YAML::Node& node);
	
public:
	Raytracer()
		{ }

	bool readScene(char* inputFilename);
	void renderToFile(char* outputFilename);
};

#endif /* end of include guard: RAYTRACER_H_6GQO67WK */
