/**** -*- Mode: C++ -*- *****************************************************
 *   PROJECT: Classroom Raytracer
 *   FILE:    misc.h
 *   CONTENT: Miscellaneous functions
 *
 *   AUTHOR:  Bert Freudenberg (bf)
 *   ADDRESS: University of Magdeburg, Germany
 *   EMAIL:   bert@isg.cs.uni-magdeburg.de
 *   RCSID:   $Id: misc.h,v 1.2 2001/11/01 16:47:46 bert Exp bert $
 *
 *****************************************************************************/

#ifndef __MISC_H
#define __MISC_H

#include <iostream>
using namespace std;

const char COMMENT_CHAR = '#';

istream& comment(istream &s);
istream& word(istream &s);

#endif
