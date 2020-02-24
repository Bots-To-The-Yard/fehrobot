#include "../include/Menu.h"
#include "FEHLCD.h"

Menu::Menu() {
  this->program = nullptr;
  this->logger = nullptr;
}

Menu::Menu(Robot* robot, Course* course, Logger* logger) {
  // Setup the pointers
  this->robot = robot;
  this->course = course;
  this->logger = logger;
}

void Menu::addProgram(Program* program) {
  // Set the program references
  program->setRobot(robot);
  program->setCourse(course);
  program->setLogger(logger);
  // Add the program to the vector
  programs.push_back(program);
}

void Menu::display() {
  while (true) {
    // Clear the program
    program = nullptr;
    logger->debug("Menu::display", "Display program selection screen");
    // Write the header
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::Blue);
    LCD.WriteAt("Team M7", 0, 0);
    LCD.SetFontColor(FEHLCD::White);
    LCD.WriteAt("Select a Program", 100, 0);
    // Display the list of programs
    logger->debug("Menu::display", "Display Program List");
    logger->info("Menu::display", "Loaded Programs:");
    for (int i = 0; i < programs.size(); i++) {
      LCD.DrawRectangle(5, 40 + (i * 40), 310, 35);
      LCD.WriteAt(programs[i]->getName(), 20, 50 + (i * 40));
      logger->info("Menu::display", "%d - %s", i + 1, programs[i]->getName());
    }
    // Wait for the user touch
    while (!LCD.Touch(&x, &y));
    // Select the program
    if (y >= 50) {
      for (int i = 0; i < programs.size(); i++) {
        if (y >= 50 + (i * 40) && y <= 35 + 50 + (i * 40)) {
          // Select the program at the index
          program = programs[i]; 
          break;
        }
      }
    }
    if (program != nullptr) {
      logger->info("Menu::display", "Program %s selected", program->getName());
      // Display the init button
      logger->debug("Menu::display", "Display program init screen");
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Init", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to Initialize the program
      while (!LCD.Touch(&x, &y));
      // Initialize the program
      logger->debug("Menu::display", "Initialize Program");
      program->init();
      // Clear the screen and display the run button
      logger->debug("Menu::display", "Display program run screen");
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Run", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to run the program
      while (!LCD.Touch(&x, &y));
      // Run the program
      logger->info("Menu::display", "Run Program: %s", program->getName());
      program->run();
    }
  }
}