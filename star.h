/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR

/*****************************************************
 * STAR
 * A star that twinkles
 *****************************************************/
class Star
{
public:
   // Randomly generate a new position using the random() function
   void reset(double width, double height);

   //Draw a star, and phase increases by one everytime this code runs.
   void draw(ogstream& gout);

private:
   Position pos;
   unsigned char phase;
};
