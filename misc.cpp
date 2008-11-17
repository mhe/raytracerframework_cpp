/****************************************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    misc.cpp
 *   CONTENT: Miscellaneous functions
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: misc.cpp,v 1.1 2000/04/10 10:21:17 bert Exp bert $
 *
 *****************************************************************************/

#include "misc.h"
#include <iostream>
#include <ctype.h>

istream& comment(istream &s)
{
  char c;
  while (s.get(c)) {
    if (!isspace(c)) {
      if (c == COMMENT_CHAR) {
	while (s.get(c) && c != '\n');
      } else {
	s.putback(c);
	break;
      }
    }
  }
  return s;
}


istream& word(istream &s)
{
  char c;
  while (s.get(c)) {
    if (!isalpha(c)) {
      s.putback(c);
      s >> comment;
      break;
    }
  }
  return s;
}
