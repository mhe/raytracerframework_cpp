/**** -*- Mode: C++ -*- *****************************************************
 *
 *   PROJECT: Classroom Raytracer
 *   FILE:    vector.h
 *   CONTENT: Declaration and inline functions for classes
 *            Vector, Point, and Ray
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: vector.h,v 1.3 2001/11/23 17:46:40 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __VECTOR_H
#define __VECTOR_H

#include <math.h>
#include <iostream>
using namespace std;

class Triple
{
protected:

  double x;
  double y;
  double z;

public:

  Triple(double X = 0, double Y = 0, double Z = 0)
    : x(X), y(Y), z(Z)
    { }
};


class Vector : public Triple
{
public:

  Vector(double X = 0, double Y = 0, double Z = 0)
    : Triple(X, Y, Z)
    { }

  Vector operator+(const Vector &v) const
    { return Vector(x+v.x, y+v.y, z+v.z); }

  Vector operator-() const
    { return Vector( -x, -y, -z); }

  Vector operator-(const Vector &v) const
    { return Vector(x-v.x, y-v.y, z-v.z); }

  double operator*(const Vector &v) const
    {return (*this).dot(v);}

  Vector operator^(const Vector &v) const
    {return (*this).cross(v);}

  Vector operator*(double f) const
    {return Vector(x*f, y*f, z*f);}

  friend Vector operator*(double f, const Vector &v)
    {return Vector(f*v.x, f*v.y, f*v.z);}

  Vector operator/(double f) const
    {return Vector(x/f, y/f, z/f);}

  Vector& operator+=(const Vector &v)
    {
      x += v.x;
      y += v.y;
      z += v.z;
      return *this;
    }

  Vector& operator-=(const Vector &v)
    {
      x -= v.x;
      y -= v.y;
      z -= v.z;
      return *this;
    }

  double dot(const Vector &v) const
    { return x*v.x + y*v.y + z*v.z; }

  Vector cross(const Vector &v) const
    {
      return Vector( y*v.z - z*v.y,
		     z*v.x - x*v.z,
		     x*v.y - y*v.x);
    }

  double length() const
    { return sqrt(length_2()); }

  double length_2() const
    { return x*x + y*y + z*z; }

  Vector normalized() const
    { return (*this) / length(); }

  double normalize()
  {
    double l = length();
    x /= l;
    y /= l;
    z /= l;
    return l;
  }

  friend istream& operator>>(istream &s, Vector &v);
  friend ostream& operator<<(ostream &s, const Vector &v);

  friend class Point;
};


class Point : public Triple
{
 public:

  Point(double X = 0, double Y = 0, double Z = 0)
    : Triple(X, Y, Z)
    { }

  Point operator+(const Vector &v) const
    { return Point(x+v.x, y+v.y, z+v.z); }

  Vector operator-(const Point &p) const
    { return Vector(x-p.x, y-p.y, z-p.z); }

  const Vector& asVector() const
    { return *(Vector*)(this); }

  friend istream& operator>>(istream &s, Point &p);
  friend ostream& operator<<(ostream &s, const Point &p);

};


class Ray
{
public:
  Point O;
  Vector D;

  Ray(const Point &from, const Vector &dir)
    : O(from), D(dir)
    { }

  Ray(const Point &from, const Point &to)
    : O(from), D(to - from)
    { D.normalize(); }

  Point at(double t) const
    { return O + t*D; }

};

#endif

