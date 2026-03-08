#include "thrust.h"


/*********************************************
 * THRUST : ROTATION
 *********************************************/
double Thrust::rotation() const
{
   if (clockwise && !counterClockwise)
   {
      return 0.01;
   }
   else if (counterClockwise && !clockwise)
   {
      return -0.01;
   }

   return 0.0;
}

/*********************************************
 * THRUST : MAINENGINETHRUST
 *********************************************/
double Thrust::mainEngineThrust() const
{
   if (mainEngine)
      return 45000.0 / 15103.0;
   return 0.0;
}

/*********************************************
 * THRUST : SET
 *********************************************/
void Thrust::set(const Interface* pUI)
{
   mainEngine = pUI->isDown();
   clockwise = pUI->isLeft();
   counterClockwise = pUI->isRight();
}


