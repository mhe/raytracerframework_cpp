/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    color.h
 *   CONTENT: Color class declaration & inline functions
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: color.h,v 1.3 2001/11/23 17:43:25 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>
#include "misc.h"

class Color
{
protected:
  // There should be no need to access the components separately

  float r;
  float g;
  float b;

  // Except for:
  friend class Image;

public:

  Color() { }
  Color(float red, float green, float blue)
    : r(red), g(green), b(blue)
  { }

  // Assign
  inline void set(float red, float green, float blue);
  inline void set(float gray);
  inline void set(int red, int green, int blue, float maxval);
  inline void set(int gray, float maxval);

  // All operations are component-wise
  inline Color operator+(const Color& c) const;
  inline Color operator*(const Color& c) const;
  inline Color operator*(float f) const;
  inline Color operator/(float f) const;

  inline friend Color operator*(float f, const Color& c);

  // Self modifying operators
  inline Color& operator+=(const Color& c);
  inline Color& operator*=(const Color& c);
  inline Color& operator*=(float f);
  inline Color& operator/=(float f);

  // Set all components > maxval to maxval
  inline void clamp(float maxval = 1.0);

  friend ostream& operator<<(ostream& s, const Color& c);
  friend istream& operator>>(istream& s, Color& c);

};


// Inline functions


// Accessors


inline void Color::set(float red, float green, float blue)
{
  r = red;
  g = green;
  b = blue;
}

inline void Color::set(float gray)
{
  r = g = b = gray;
}

inline void Color::set(int red, int green, int blue, float maxval)
{
  set(red / maxval, green / maxval, blue / maxval);
}

inline void Color::set(int gray, float maxval)
{
  set(gray / maxval);
}


// Operators


inline Color Color::operator+(const Color& c) const
{
  return Color(r+c.r, g+c.g, b+c.b);
}

inline Color Color::operator*(const Color& c) const
{
  return Color(r*c.r, g*c.g, b*c.b);
}

inline Color Color::operator*(float f) const
{
  return Color(r*f, g*f, b*f);
}

inline Color Color::operator/(float f) const
{
  return Color(r/f, g/f, b/f);
}

inline Color operator*(float f, const Color& c)
{
  return c * f;
}


// Self modifying operators


inline Color& Color::operator+=(const Color& c)
{
  r += c.r;
  g += c.g;
  b += c.b;
  return *this;
}

inline Color& Color::operator*=(const Color& c)
{
  r *= c.r;
  g *= c.g;
  b *= c.b;
  return *this;
}


inline Color& Color::operator*=(float f)
{
  r *= f;
  g *= f;
  b *= f;
  return *this;
}


inline Color& Color::operator/=(float f)
{
  r /= f;
  g /= f;
  b /= f;
  return *this;
}


// Other functions


inline void Color::clamp(float maxval)
{
  if (r > maxval) r = maxval;
  if (g > maxval) g = maxval;
  if (b > maxval) b = maxval;
}

#endif
