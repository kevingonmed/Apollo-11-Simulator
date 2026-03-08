/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
  * ANGLE : REVERSE
  ************************************/
void Angle::reverse()
{
   radians += M_PI;
   radians = normalize(radians);
}

/************************************
  * ANGLE : ADD
  ************************************/
Angle& Angle::add(double delta)
{
   radians += delta;
   radians = normalize(radians);
   return *this;
}

/************************************
  * ANGLE : convertToDegrees
  ************************************/
double Angle::convertToDegrees(double radiansNew) const
{
   return radiansNew * 180 / M_PI;
}

/************************************
  * ANGLE : convertToRadians
  ************************************/
double Angle::convertToRadians(double degrees) const
{
   return degrees * M_PI / 180.0;
}

/************************************
  * ANGLE : NORMALIZE
  ************************************/
double Angle::normalize(double radiansNew) const
{
   while (radiansNew < 0)
      radiansNew += 2 * M_PI;
   while (radiansNew >= 2 * M_PI)
      radiansNew -= 2 * M_PI;
   return radiansNew;
}

