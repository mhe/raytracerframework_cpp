/****************************************************************************
*   PROJECT: Classroom Raytracer
*   FILE:    image.cpp
*   CONTENT: Image class implementation
*
*   AUTHOR:  Bert Freudenberg (bf)
*   ADDRESS: University of Magdeburg, Germany
*   EMAIL:   bert@isg.cs.uni-magdeburg.de
*   RCSID:   $Id: image.cpp,v 1.4 2001/11/23 17:42:30 bert Exp bert $
*
*   NOTES:   Most functions are inlined, see image.h
*
*****************************************************************************/

#include "image.h"
#include "lodepng.h"
#include <fstream>

/*
 * Create a picture. Answer false if failed.
 */
bool Image::set_extent(int width, int height)
{
	_width = width;
	_height = height;
	if (_pixel) delete[] _pixel;
	_pixel = size() > 0 ? new Color[size()] : 0;
	return _pixel != 0;
}


void Image::write_png(char* filename) const
{
	std::vector<unsigned char> image;
	image.resize(_width * _height * 4);
	std::vector<unsigned char>::iterator imageIterator = image.begin();
	Color *currentPixel = _pixel;
	while (imageIterator != image.end()) {
		*imageIterator = currentPixel->r * 255;
		imageIterator++;
		*imageIterator = currentPixel->g * 255;
		imageIterator++;
		*imageIterator = currentPixel->b * 255;
		imageIterator++;
		*imageIterator = 255;
		imageIterator++;
		currentPixel++;
	}
	LodePNG::encode(filename, image, _width, _height);
}


void Image::read_png(char* filename)
{
	std::vector<unsigned char> buffer, image;
	 //load the image file with given filename
	LodePNG::loadFile(buffer, filename);
	
	 //decode the png
	LodePNG::Decoder decoder;
	decoder.decode(image, buffer.empty() ? 0 : &buffer[0], (unsigned)buffer.size());
	cout << decoder.getChannels() << endl;
	cout << decoder.getBpp() << endl;
	
	if (decoder.getChannels()<3 || decoder.getBpp()<24) {
		cerr << "Error: only color (RGBA), 8 bit per channel png images are supported." << endl;
		cerr << "Either convert your image or change the sourcecode." << endl;
		exit(1);
	}
	int w = decoder.getWidth();
	int h = decoder.getHeight();
	set_extent(w,h);
	
	// now convert the image data
	std::vector<unsigned char>::iterator imageIterator = image.begin();
	Color *currentPixel = _pixel;
	while (imageIterator != image.end()) {
		currentPixel->r = (*imageIterator)/255.0;
		imageIterator++;
		currentPixel->g = (*imageIterator)/255.0;
		imageIterator++;
		currentPixel->b = (*imageIterator)/255.0;
		imageIterator++;
		// Let's just ignore the alpha channel
		imageIterator++; 
		currentPixel++;
	}	
}
