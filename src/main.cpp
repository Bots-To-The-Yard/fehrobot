#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHSD.h>
#include "../include/Robot.h"
#include "../include/Menu.h"
#include "programs/Exploration02.h"
#include "programs/DriveForward.h"
#include "programs/BackwardsUpRamp.h"
#include "programs/Performance01.h"
#include "programs/CdSCellTest.h"
using namespace program;

int main() {
  // Create a new logger
  Logger logger(Debug);
  // Open the log file
  logger.open("log.txt");
  // Declare the robot and the course
  Course course;
  Robot robot(&logger);

  // Define the programs
  Exploration02 exploration02(&robot, &course, &logger);
  DriveForward driveForward(&robot, &course, &logger);
  BackwardsUpRamp backwardsUpRamp(&robot, &course, &logger);
  Performance01 performance01(&robot, &course, &logger);
  CdSCellTest cdsCellTest(&robot, &course, &logger);

  // Define the program array
  Program* programs[] = {
    &exploration02,
    &driveForward,
    &backwardsUpRamp,
    &performance01,
    &cdsCellTest
  };

  // Define the menu
  Menu menu(programs, 5, &logger);

  // Display the program selection menu
  menu.display();

  // Close the log file
  logger.close();

  return 0;
}