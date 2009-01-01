// 
//  scene.h
//  newobjectmodel
//  
//  Created by Maarten Everts on 2009-01-01.
//  Copyright 2009 University of Groningen. All rights reserved.
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
	int numObjects;
	Object* objects[MAX_OBJECTS];
	int numLights;
	Light* lights[MAX_LIGHTS];
	Triple eye;
public:
	Scene() : numObjects(0), numLights(0) { }
	Color trace(const Ray &ray);
	void render(Image &img);
	void addObject(Object *o);
	void addLight(Light *l);
	void setEye(Triple e);
};

#endif /* end of include guard: SCENE_H_KNBLQLP6 */
