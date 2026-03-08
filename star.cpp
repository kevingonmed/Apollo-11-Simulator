/***********************************************************************
 * Source File:
 *    STAR
 * Author:
 *    David and Kevin
 * Summary:
 *    We are drawing stars
 ************************************************************************/
#include "star.h"

/******************************************
* STAR : RESET
*****************************************/
void Star::reset(double width, double height)
{
   double randomWidth = random(0.0, width);
   double randomHeight = random(0.0, height);
   pos.setX(randomWidth);
   pos.setY(randomHeight);
   phase = random(0.0, 255.0);
}

/******************************************
* STAR : DRAW
*****************************************/
void Star::draw(ogstream& gout)
{
   gout.drawStar(pos, phase++);
}
