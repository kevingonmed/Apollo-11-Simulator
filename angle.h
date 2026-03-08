/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;

   // Constructors
   Angle() : radians(0.0) {}
   Angle(const Angle& rhs) : radians(rhs.radians) {}
   Angle(double degrees) : radians(convertToRadians(degrees)) {}

   // Getters
   double getDegrees() const { return convertToDegrees(radians); }
   double getRadians() const { return radians; }

   // Setters
   void setDegrees(double degrees)    { radians = normalize(convertToRadians(degrees)); }
   void setRadians(double radiansNew) { radians = normalize(radiansNew); }
   void setUp()                       { radians = convertToRadians(0.0); }
   void setDown()                     { radians = convertToRadians(180.0); }
   void setRight()                    { radians = convertToRadians(90.0); }
   void setLeft()                     { radians = convertToRadians(270.0); }
   void reverse();
   Angle& add(double delta);

private:
   // Conversion
   double convertToDegrees(double radiansNew) const;
   double convertToRadians(double degrees) const;
   double normalize(double radiansNew) const;

   double radians;   // 360 degrees equals 2 PI radians
};