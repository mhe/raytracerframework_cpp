// 
//  scene.cpp
//  newobjectmodel
//  
//  Created by Maarten Everts on 2009-01-01.
//  Copyright 2009 University of Groningen. All rights reserved.
// 
#include "scene.h"
#include "material.h"

Color Scene::trace(const Ray &ray)
{
	// Find hit object and distance
	double t, min_t = 0.0;
	Object *obj = NULL;
	for (int i = 0; i < numObjects; ++i) {
		if (objects[i]->intersect(ray, &t) && (!obj || t < min_t)) {
			min_t = t;
			obj = objects[i];
		}
	}
	
	// No hit? Return background color.
	if (!obj) return Color(0.0, 0.0, 0.0);

	Material *material = obj->material;            //the hit objects material
	Point hit = ray.at(min_t);                     //the hit point
	Vector N = obj->normal(hit);                   //the normal at hit point
	Vector V = -ray.D;                             //the view vector


	/****************************************************
	* This is where you should insert the color
	* calculation (Phong model).
	*
	* Given: material, hit, N, V, lights[]
	* Sought: color
	*
	* Hints: (see triple.h)
	*        Vector.dot(Vector) dot product
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

void Scene::render(Image &img)
{
	int w = img.width();
	int h = img.height();
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			Point pixel(x, h-1-y, 0);
			Ray ray(eye, (pixel-eye).normalized());
			Color col = trace(ray);
			col.clamp();
			img(x,y) = col;
		}
	}	
}

void Scene::addObject(Object *o)
{
	objects[numObjects] = o;
	numObjects += 1;
}

void Scene::addLight(Light *l)
{
	lights[numLights] = l;
	numLights += 1;
}

void Scene::setEye(Triple e)
{
	eye = e;
}

