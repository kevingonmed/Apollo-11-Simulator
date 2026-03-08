/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "acceleration.h"// for ACCELERATION
#include "lander.h"      // for LANDER
#include "star.h"        // for STAR
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
using namespace std;


/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) : ground(posUpperRight), lander(posUpperRight), posUpperRight(posUpperRight) 
   {
      // initialize all stars ONCE
      for (int i = 0; i < NUM_STARS; i++)
         stars[i].reset(posUpperRight.getX(), posUpperRight.getY());
   }
   Ground ground;
   Lander lander;
   Thrust thrust;
   Position posUpperRight;
   int delayFrames = 0;
   string endText;
   static const int NUM_STARS = 50;
   Star stars[NUM_STARS];
};



/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator * pSimulator = (Simulator *)p;
   Position posTest(200.0, 300.0);
   ogstream gout;
   if (pSimulator->delayFrames > 0)
   {
      pSimulator->delayFrames--;

      pSimulator->ground.draw(gout);
      pSimulator->lander.draw(pSimulator->thrust, gout);

      string endText = pSimulator->lander.isDead() ? "You are dead :(" : "You survived!!!!";

      gout.drawText(posTest, endText.c_str());

      return;
   }

   // draw the stars
   for (int i = 0; i < Simulator::NUM_STARS; i++)
      pSimulator->stars[i].draw(gout);
      

   // draw the ground
   
   pSimulator->ground.draw(gout);

   // draw lander
   pSimulator->lander.draw(pSimulator->thrust, gout);
   if (pSimulator->lander.isDead())
   {
      pSimulator->lander.reset(pSimulator->posUpperRight);
   }
   pSimulator->thrust.set(pUI);
   pSimulator->lander.coast(pSimulator->lander.input(pSimulator->thrust, -1.65), 0.20);
   // game ends 
   
  

   if (pSimulator->ground.hitGround(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
   {
      
      pSimulator->lander.crash();
      pSimulator->delayFrames = 60;
      pSimulator->ground.reset();

   }
   else if(pSimulator->ground.onPlatform(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
   {
      pSimulator->lander.land();
      pSimulator->delayFrames = 60;
      pSimulator->ground.reset();
      
   }
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 * Kevin and David
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   
   
   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   // set everything into action
   ui.run(callBack, (void *)&simulator);

   return 0;
}
