#include "../include/Menu.h"
#include "FEHLCD.h"

Menu::Menu() {
  this->programs = nullptr;
  this->program = nullptr;
  this->logger = nullptr;
  this->programCount = 0;
}

Menu::Menu(Program** programs, int programCount, Logger* logger) {
  this->programs = programs;
  this->programCount = programCount;
  this->logger = logger;
}

void Menu::display() {
  while (true) {
    // Clear the program
    program = nullptr;
    logger->debug("Display program selection screen");
    // Write the header
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::Blue);
    LCD.WriteAt("Team M7", 0, 0);
    LCD.SetFontColor(FEHLCD::White);
    LCD.WriteAt("Select a Program", 100, 0);
    // Display the list of programs
    logger->debug("Display Program List");
    logger->info("LOADED PROGRAMS:");
    for (int i = 0; i < programCount; i++) {
      LCD.DrawRectangle(5, 40 + (i * 40), 310, 35);
      LCD.WriteAt(programs[i]->getName(), 20, 50 + (i * 40));
      logger->info("%d - %s", i + 1, programs[i]->getName());
    }
    // Wait for the user touch
    while (!LCD.Touch(&x, &y));
    // Select the program
    if (y >= 50) {
      for (int i = 0; i < programCount; i++) {
        if (y >= 50 + (i * 40) && y <= 35 + 50 + (i * 40)) {
          // Select the program at the index
          program = programs[i]; 
          break;
        }
      }
    }
    if (program != nullptr) {
      logger->info("Program %s selected", program->getName());
      // Display the init button
      logger->debug("Display program init screen");
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Init", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to Initialize the program
      while (!LCD.Touch(&x, &y));
      // Initialize the program
      logger->debug("Initialize Program");
      program->init();
      // Clear the screen and display the run button
      logger->debug("Display program run screen");
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Run", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to run the program
      while (!LCD.Touch(&x, &y));
      // Run the program
      logger->info("Run program %s", program->getName());
      program->run();
    }
  }
}