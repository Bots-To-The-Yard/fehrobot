#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHSD.h>
#include "../include/Robot.h"
#include "../include/Menu.h"
#include "programs/Exploration02.h"
using namespace program;

int main() {
  FEHFile* logFile = SD.FOpen("log.txt","w");
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

  // Close the log file
  SD.FClose(logFile);

  return 0;
}