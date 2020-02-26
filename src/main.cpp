#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHSD.h>
#include <vector>
#include "../include/Robot.h"
#include "../include/Menu.h"
#include "programs/Exploration02.h"
#include "programs/DriveForward.h"
#include "programs/BackwardsUpRamp.h"
#include "programs/Performance01.h"
#include "programs/Performance02.h"
#include "programs/CdSCellTest.h"
using namespace program;
using namespace std;

int main() {
  vector<int> values;
  values.push_back(2);
  values.push_back(4);
  // Create a new logger
  Logger logger(Debug);
  // Open the log file
  logger.open("log.txt");
  // Declare the robot and the course
  Course course;
  Robot robot(&logger);
  // Define the menu
  Menu menu(&robot, &course, &logger);
  // Add the programs to the menu
  menu.addProgram(new Performance01());
  menu.addProgram(new DriveForward());
  menu.addProgram(new Performance02());
  // Display the program selection menu
  menu.display();
  // Close the log file
  logger.close();

  return 0;
}