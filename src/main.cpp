#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include "../include/Robot.h"
#include "../include/Menu.h"
#include "programs/Exploration02.h"
using namespace program;

int main() {
  // Declare the robot and the course
  Course course;
  Robot robot;

  // Define the programs
  Exploration02 exploration02(&robot, &course);

  // Define the program array
  Program* programs[] = {
    &exploration02
  };

  // Define the menu
  Menu menu(programs, 1);

  // Display the program selection menu
  menu.display();

  // LCD.Clear(FEHLCD::Black);
  robot.turnLeftDegree(180,DEFAULT_PERCENT);
  // float x;
  // float y;
  // while (!LCD.Touch(&x, &y));

  // exploration02.run();

  return 0;
}