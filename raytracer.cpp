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
#include <fstream>


// Functions to ease reading form YAML input

void operator >> (const YAML::Node& node, Triple& t)
{
	assert(node.size()==3);
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

Light* parseLight(const YAML::Node& node)
{
	Light* light = new Light();
	node["position"] >> light->P;
	node["color"] >> light->color;
	return light;
}

/*
 * Read a scene from file
 */

bool Raytracer::readScene(char* inputFilename)
{
	scene = new Scene();

	std::ifstream fin(inputFilename);
	YAML::Parser parser(fin);
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
		
		const YAML::Node& sceneLights = doc["Lights"];
		if (sceneObjects.GetType() != YAML::CT_SEQUENCE) {
			cerr << "Error: expected a list of lights." << endl;
			return false;
		}
		for(YAML::Iterator it=sceneLights.begin();it!=sceneLights.end();++it) {
			scene->addLight(parseLight(*it));
		}
		
    }
	return true;
}

void Raytracer::renderToFile(char* outputFilename)
{
	Image img(400,400);
	cout << "Tracing..." << endl;
	scene->render(img);
	cout << "Writing image to " << outputFilename << "..." << endl;
	img.write_png(outputFilename);
	cout << "Done." << endl;
}