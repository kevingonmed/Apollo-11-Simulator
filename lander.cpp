/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"



 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   angle.setUp();
   status = PLAYING;
   fuel = 5000.0;

   double randomVelX = random(-10.0, -4.0);
   double randomVelY = random(-2.0, 2.0);
   velocity.setDX(randomVelX);
   velocity.setDY(randomVelY);

   pos.setX(posUpperRight.getX() - 1);
   pos.setY(posUpperRight.getY() * random(0.75, 0.95));
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
   gout.drawLander(pos, angle.getDegrees());

   if (isFlying() && fuel > 0.0);
      gout.drawLanderFlames(pos, angle.getDegrees(), 
         thrust.isMain(), thrust.isClock(), thrust.isCounter());
}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander :: input(const Thrust& thrust, double gravity)
{
   Acceleration newAcceleration;

   double rotation = thrust.rotation();
   if (rotation != 0.0 && fuel >= 1.0)
   {
      angle.add(rotation);
      fuel -= 1.0;
   }

   newAcceleration.setDDX(0.0);
   newAcceleration.setDDY(gravity);

   if (thrust.isMain() && fuel >= 10.0)
   {
      fuel -= 10.0;

      double forceThrust = thrust.mainEngineThrust();
      Acceleration temp;
      Angle flipped = angle;
      flipped.setRadians(-angle.getRadians());
      temp.set(flipped, forceThrust);
      newAcceleration.add(temp);
      
   }

   return newAcceleration;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander::coast(Acceleration& acceleration, double time)
{
   velocity.add(acceleration, time);
   pos.add(acceleration, velocity, time);
  
}
