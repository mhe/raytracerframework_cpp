//
//  Framework for a raytracer
//  File: scene.h
//
//  Created for the Computer Science course "Introduction Computer Graphics"
//  taught at the University of Groningen by Tobias Isenberg.
//
//  Author: Maarten Everts
//
//  This framework is inspired by and uses code of the raytracer framework of 
//  Bert Freudenberg that can be found at
//  http://isgwww.cs.uni-magdeburg.de/graphik/lehre/cg2/projekt/rtprojekt.html 
//

#ifndef SCENE_H_KNBLQLP6
#define SCENE_H_KNBLQLP6

#include "triple.h"
#include "light.h"
#include "object.h"
#include "image.h"

const int MAX_OBJECTS = 100;
const int MAX_LIGHTS  = 10;

class Scene
{
private:
	unsigned int numObjects;
	Object* objects[MAX_OBJECTS];
	unsigned int numLights;
	Light* lights[MAX_LIGHTS];
	Triple eye;
public:
	Scene() : numObjects(0), numLights(0) { }
	Color trace(const Ray &ray);
	void render(Image &img);
	void addObject(Object *o);
	void addLight(Light *l);
	void setEye(Triple e);
	unsigned int getNumObjects() { return numObjects; }
	unsigned int getNumLights() { return numLights; }
};

#endif /* end of include guard: SCENE_H_KNBLQLP6 */
