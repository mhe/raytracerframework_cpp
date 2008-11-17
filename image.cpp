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
#include "misc.h"
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


/*
 * Write to RGB image
 * All colors must be in (0, 1) range!
 */
void Image::write_ppm(ostream& s, bool bin) const
{
  // Write header
  s << (bin ? "P6" : "P3") << endl
    << _width << ' ' << _height << endl
    << 255 << '\n';
  if (!bin) {
    // Text format - this one is easy
    for (int i = 0; i < size(); i++)
      s << (unsigned char)(_pixel[i].r * 255) << ' '
	<< (unsigned char)(_pixel[i].g * 255) << ' '
	<< (unsigned char)(_pixel[i].b * 255) << endl;
  } else {
    // Binary format - write line-by-line
    int len = _width * 3;
    unsigned char *buf = new unsigned char[len];
    Color *color = _pixel;
    for (int y = 0; y < _height; y++) {
      unsigned char *p = buf;
      for (int x = 0; x < _width; x++) {
	*p++ = (unsigned char)(color->r * 255);
	*p++ = (unsigned char)(color->g * 255);
	*p++ = (unsigned char)(color->b * 255);
	color++;
      }
      s.write((char*)buf, len);
    }
    delete[] buf;
  }
}


/*
 * Read an image, discarding whatever was in before
 */
bool Image::read_ppm(istream& s)
{
  char p, id;
  int width, height, maxval;
  // Get header
  s >> p >> id >> comment
    >> width >> height;
  // Paranoia
  if (p != 'P' || id < '1' || id > '6'
      || width <= 0 || height <= 0) {
    cerr << "Bad ppm header!\n";
    return false;
  }
  // Create image
  if (!set_extent(width, height)) return false;
  // Check ASCII / binary format
  bool ascii = id < '4';
  typedef enum {BW, GRAY, RGB} FORMAT;
  FORMAT format = (FORMAT) (ascii ? id - '1' : id - '4');
  // Get Maxval
  if (format != BW)
    s >> comment >> maxval;
  else
    maxval = 1;
  // Read
  int r, g, b, gray, mask;
  if (ascii) {
    s >> comment; // Skip to data
    for (int i=0; i < size(); i++) {
      if (format == RGB) {
	s >> r >> g >> b;
	_pixel[i].set(r, g, b, maxval);
      } else { // BW, GRAY
	s >> gray;
	_pixel[i].set(gray, maxval);
      }
    }
  } else { // not ASCII
    s.get();  // Skip to data
    // Line buffer
    int len = _width;
    if (format == BW) len = (len + 7) / 8;
    if (format == RGB) len *= 3;
    unsigned char *buf = new unsigned char[len];
    // Destination
    Color *color = _pixel;
    // For each line
    for (int y = 0; y < _height; y++) {
      s.read((char*)buf, len);
      unsigned char *p = buf;
      // For each pixel
      for (int x = 0; x < _width; x++) {
	switch (format) {
	  case BW:
	    mask = 0x80 >> (x & 7);       //highest bit is on the left
	    gray = (*p & mask) ? 0 : 1;   //a set bit means black!
	    color++->set(gray, maxval);
	    if (mask == 1) p++;           //increment every 8th pixel
	    break;
	  case GRAY:                      //this case is easy
	    gray = *p++;
	    color++->set(gray, maxval);
	    break;
	  case RGB:                       //this one, too
	    r = *p++;
	    g = *p++;
	    b = *p++;
	    color++->set(r, g, b, maxval);
	    break;
	}
      }
    }
    delete[] buf;
  }
  return true;
}
