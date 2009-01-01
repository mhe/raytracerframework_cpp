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
#include "yaml/yaml.h"
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


// Functions to ease reading form YAML input

void operator >> (const YAML::Node& node, Triple& t)
{
    node[0] >> t.x;
    node[1] >> t.y;
    node[2] >> t.z;
}

Triple parseTriple(const YAML::Node& node)
{
	Triple t;
    node[0] >> t.x;
    node[1] >> t.y;
    node[2] >> t.z;	
	return t;
}

Material* parseMaterial(const YAML::Node& node)
{
	Material *m = new Material();
	node["color"] >> m->color;	
	node["ka"] >> m->ka;
	node["kd"] >> m->kd;
	node["ks"] >> m->ks;
	node["n"] >> m->n;
	return m;
}

Object* parseObject(const YAML::Node& node)
{
	Object *returnObject = NULL;
	std::string objectType;
	node["type"] >> objectType;
	if (objectType.compare("sphere") == 0) {
		
		Triple pos;
		node["position"] >> pos;
		double r;
		node["radius"] >> r;
		Sphere *sphere = new Sphere(pos,r);
		returnObject = sphere;
	}
	if (returnObject) {
		// read the material
		returnObject->material = parseMaterial(node["material"]);
	}
	return returnObject;
}

/*
 * Read a scene from file
 */

bool Raytracer::read(istream& is)
{
	scene = new Scene();
	YAML::Parser parser(is);
	while(parser) {
        YAML::Node doc;
        parser.GetNextDocument(doc);

		scene->setEye(parseTriple(doc["Eye"]));
		
		const YAML::Node& sceneObjects = doc["Objects"];
		if (sceneObjects.GetType() != YAML::CT_SEQUENCE) {
			cerr << "Error: expected a list of objects." << endl;
			return false;
		}
		for(YAML::Iterator it=sceneObjects.begin();it!=sceneObjects.end();++it) {
			Object *obj = parseObject(*it);
			// Only add object if it is recognized
			if (obj) {
				scene->addObject(obj);
			}
		}
    }
	return true;
}


