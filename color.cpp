/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    color.cpp
 *   CONTENT: Color class implementation
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: color.cpp,v 1.1 2000/04/10 10:21:17 bert Exp bert $
 *
 *   NOTES:   Most functions are inlined, see color.h
 *
 *****************************************************************************/

#include <iostream>
#include "color.h"

// Write format is "<r g b>"
ostream& operator<<(ostream& s, const Color& c)
{
  return s << '<' << c.r << ' ' << c.g << ' ' << c.b << '>';
}

// Read, skipping angle brackets if necessary
istream& operator>>(istream& s, Color& c)
{
  char ch;
  s >> ch;
  if (ch != '<') s.putback(ch);
  s >> c.r >> c.g >> c.b;
  if (ch == '<') s >> ch;
  return s;
}
