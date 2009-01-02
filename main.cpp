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
#include <fstream>


int main(int argc, char *argv[])
{
	cout << "Introduction to Computer Graphics - Raytracer" << endl << endl;
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " in-file out-file.png" << endl;
		return 1;
	}

	Raytracer raytracer;

	if (!raytracer.readScene(argv[1])) {
		cerr << "Error reading scene from " << argv[1] << endl;
	}
	raytracer.renderToFile(argv[2]);
	
	return 0;
}


