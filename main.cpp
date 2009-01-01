/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    main.cpp
 *   CONTENT: Main program
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: main.cpp,v 1.4 2002/11/20 20:22:30 bert Exp bert $
 *
 *****************************************************************************/

#include "raytracer.h"
#include "image.h"
#include "yaml/yaml.h"
#include <fstream>

void yamltest()
{
	std::ifstream fin("scene01.yaml");
    YAML::Parser parser(fin);

    while(parser) {
        YAML::Node doc;
        parser.GetNextDocument(doc);
		std::string rendertype;
		doc["RenderType"] >> rendertype;
		cout << "The render type is: " << rendertype << endl;
		const YAML::Node& sceneObjects = doc["Objects"];
		if (sceneObjects.GetType() == YAML::CT_SEQUENCE) {
			cout << "Yes it is a sequence!" << endl;
		}
		for(YAML::Iterator it=sceneObjects.begin();it!=sceneObjects.end();++it) {
		    std::cout << "Object type: " << (*it)["type"] << std::endl;
			const YAML::Node& material = (*it)["material"];
			cout << "Node type: " << material.GetType() << endl;
			cout << "is alias: " << material.IsAlias() << endl;
			cout << "" << material.GetAnchor() << endl;
			// cout << "Material: " << endl;
			// cout << " ka: " << material["ka"] << endl;
			// cout << " kd: " << material["kd"] << endl;
			// cout << " ks: " << material["ks"] << endl;
		}
    }
}

int main(int argc, char *argv[])
{
	//yamltest();
  if (argc < 3) {
    cerr << "Usage: " << argv[0] << " in-file out-file.ppm" << endl;
    return 1;
  }

  ifstream is(argv[1]);
  if (!is) {
    cerr << "File not found: " << argv[1] << endl;
    return 1;
  }

  ofstream os(argv[2], ios::binary);
  if (!os) {
    cerr << "Cannot write to: " << argv[2] << endl;
    return 1;
  }

  Raytracer raytracer;

  cerr << "Reading from " << argv[1] << endl;
  if (!raytracer.read(is)) {
    cerr << "Error while reading!" << endl;
    return 1;
  }

  Image img(400,400);

  cerr << "Tracing" << endl;
  raytracer.trace(img);

  cerr << "Writing to " << argv[2] << endl;

  // img.write_ppm(os, true);
img.write_png(std::string(argv[2]));

  cerr << "Done" << endl;
  return 0;
}


