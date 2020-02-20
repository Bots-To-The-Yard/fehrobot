#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHSD.h>
#include "../include/Robot.h"
#include "../include/Menu.h"
#include "programs/Exploration02.h"
#include "programs/DriveForward.h"
#include "programs/BackwardsUpRamp.h"
using namespace program;

int main() {
  // Create a new logger
  Logger logger(Debug, Debug);
  // Open the log file
  logger.open("log.txt");
  // Declare the robot and the course
  Course course;
  Robot robot(&logger);

  // Define the programs
  Exploration02 exploration02(&robot, &course);
  DriveForward driveForward(&robot, &course);
  BackwardsUpRamp backwardsUpRamp(&robot, &course);

  // Define the program array
  Program* programs[] = {
    &exploration02,
    &driveForward,
    &backwardsUpRamp
  };

  // Define the menu
  Menu menu(programs, 3);

  // Display the program selection menu
  menu.display();

  return 0;
}