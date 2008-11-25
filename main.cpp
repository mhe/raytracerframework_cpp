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


