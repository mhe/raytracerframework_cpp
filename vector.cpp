/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    vector.cpp
 *   CONTENT: Vector/Point functions
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: vector.cpp,v 1.2 2001/11/23 17:44:57 bert Exp bert $
 *
 *   NOTES:   Most functions are inlined, see vector.h
 *
 *****************************************************************************/

#include "vector.h"
#include <iostream>

// Vector

ostream& operator<<(ostream& s, const Vector& v) 
{
  return s << '[' << v.x << ' ' << v.y << ' ' << v.z << ']';
}

istream& operator>>(istream& s, Vector& v) 
{
  char ch;
  s >> ch;
  if (ch != '[') s.putback(ch);
  double x, y, z;
  s >> x >> y >> z;
  if (ch == '[') s >> ch;
  if (s) v = Vector(x, y, z);
  return s;
}

// Point

ostream& operator<<(ostream& s, const Point& p) 
{
  return s << '(' << p.x << ' ' << p.y << ' ' << p.z << ')';
}

istream& operator>>(istream& s, Point& p) 
{
  char ch;
  s >> ch;
  if (ch != '(') s.putback(ch);
  double x, y, z;
  s >> x >> y >> z;
  if (ch == '(') s >> ch;
  if (s) p = Point(x, y, z);
  return s;
}
