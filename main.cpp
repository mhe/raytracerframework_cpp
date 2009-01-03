//
//  Framework for a raytracer
//  File: main.cpp
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

#include "raytracer.h"

int main(int argc, char *argv[])
{
	cout << "Introduction to Computer Graphics - Raytracer" << endl << endl;
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " in-file out-file.png" << endl;
		return 1;
	}

	Raytracer raytracer;

	if (!raytracer.readScene(argv[1])) {
		cerr << "Error: reading scene from " << argv[1] << " failed - no output generated."<< endl;
		return 1;
	}
	raytracer.renderToFile(argv[2]);
	
	return 0;
}


