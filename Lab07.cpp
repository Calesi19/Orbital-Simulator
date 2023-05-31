/*************************************************************
 * Authors:
 * Jake Rammell
 * Hunter Powell
 * Carlos Lespin-Silva
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "physics.h"
#include "test.h"
#include "star.h"
#include "gps.h"
#include "sputnik.h"
#include "hubble.h"
#include "dragon.h"
#include "starlink.h"
#include "ship.h"
#include "earth.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      // for new gps
      ptGPS.setMetersX(0);
      ptGPS.setMetersY(42164000);
      Velocity vel(3100.0, 0);
      Direction dir;
      GPS* gps = new GPS(ptGPS, vel, dir);
      satellites.push_back(gps);
      
      // for new Sputnik
      ptSputnik.setMeters(-36515095.13, 21082000.0);
      Velocity sputnikVel(2050.0, 2684.68);
      Direction sputnikDir;
      sputnikDir.setDxDy(sputnikVel.getDx(), sputnikVel.getDy());
      Sputnik* sputnik = new Sputnik(ptSputnik, sputnikVel, sputnikDir);
      satellites.push_back(sputnik);

      // for new Hubble
      ptHubble.setMeters(0.0, -42164000.0);
      Velocity hubVel(3100.0, 0.0);
      Direction hubDir;
      hubDir.setDxDy(hubVel.getDx(), hubVel.getDy());
      Hubble* hubble = new Hubble(ptHubble, hubVel, hubDir);
      satellites.push_back(hubble);

      // for new Dragon
      ptCrewDragon.setMeters(0.0, 8000000.0);
      Velocity dragVel(-7900.0, 0.0);
      Direction dragDir;
      dragDir.setDxDy(dragVel.getDx(), dragVel.getDy());
      Dragon* dragon = new Dragon(ptCrewDragon, dragVel, dragDir);
      satellites.push_back(dragon);
      

      // for new Starlink
      ptStarlink.setMeters(0.0, -13020000.0);
      Velocity starlinkVel(5800.0, 0.0);
      Direction starlinkDir;
      starlinkDir.setDxDy(starlinkVel.getDx(), starlinkVel.getDy());
      Starlink* starlink = new Starlink(ptStarlink, starlinkVel, starlinkDir);
      satellites.push_back(starlink);

      // for new ship
      ptShip.setPixelsX(-450.0);
      ptShip.setPixelsY(450.0);
      Velocity shipVel(0.0, -2000.0);
      Direction shipDir;
      shipDir.setDown();
      Ship* ship = new Ship(ptShip, shipVel, shipDir);
      satellites.push_back(ship);

      // for new Earth
      Position ptEarth(0.0, 0.0);
      Velocity velEarth(0.0, 0.0);
      Direction dirEarth(0.0);
      Earth* earth = new Earth(ptEarth, velEarth, dirEarth);
      satellites.push_back(earth);
          
   }

   
   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   
  
   Position ptUpperRight;

   Physics physics;
   Star stars[200];


   vector<Satellite*> satellites;


   void findCollisions()
   {
       int vectSize = satellites.size();
       for (int i = 0; i < vectSize; i++)
       {
           for (int j = i + 1; j < vectSize; j++)
           {
               if (isCollided(satellites[i], satellites[j]))
               {
                   satellites[i]->kill();
                   satellites[j]->kill();
               }
           }
       }
   }

   bool isCollided(Satellite* sat1, Satellite* sat2)
   {
       return computeDistancePixels(sat1->getPosition(), sat2->getPosition()) < (sat1->getRadius() + sat2->getRadius());
   }

};


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   // draw stars
   for (int i = 0; i < 200; i++)
   {
       pDemo->stars[i].incrementPhase();
       pDemo->stars[i].draw();
   }

   vector<Satellite*> satellitesToAdd;
   auto it = pDemo->satellites.begin();
   for (it; it < pDemo->satellites.end(); it++)
   {
       (*it)->input(pUI, satellitesToAdd);
       (*it)->move(48);
       (*it)->draw();
   }

   pDemo->findCollisions();
  

   // destroy dead satellites
   it = pDemo->satellites.begin();
   for (it; it < pDemo->satellites.end(); it++)
   {
       if ((*it)->isDead())
           (*it)->destroy(pDemo->satellites, satellitesToAdd);
   }

   // add new satellites
   for (int i = 0; i < satellitesToAdd.size(); i++)
   {
       Satellite* sat = satellitesToAdd[i];
       pDemo->satellites.push_back(sat);
   }
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

    testRunner();


   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
