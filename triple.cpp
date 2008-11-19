// 
//  triple.cpp
//  current
//  
//  Created by Maarten Everts on 2008-11-18.
//  Copyright 2008 University of Groningen. All rights reserved.
// 

#include "triple.h"

ostream& operator<<(ostream& s, const Triple& v) 
{
  return s << '[' << v.x << ' ' << v.y << ' ' << v.z << ']';
}

istream& operator>>(istream& s, Triple& v) 
{
  char ch;
  s >> ch;
  if (ch != '[') s.putback(ch);
  double x, y, z;
  s >> x >> y >> z;
  if (ch == '[') s >> ch;
  if (s) v = Triple(x, y, z);
  return s;
}
