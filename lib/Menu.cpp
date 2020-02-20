#include "../include/Menu.h"
#include "FEHLCD.h"

Menu::Menu() {
  this->programs = nullptr;
  this->program = nullptr;
  this->programCount = 0;
}

Menu::Menu(Program** programs, int programCount) {
  this->programs = programs;
  this->programCount = programCount;
}

void Menu::display() {
  while (true) {
    // Clear the program
    program = nullptr;
    // Write the header
    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::Blue);
    LCD.WriteAt("Team M7", 0, 0);
    LCD.SetFontColor(FEHLCD::White);
    LCD.WriteAt("Select a Program", 100, 0);
    // Display the list of programs
    for (int i = 0; i < programCount; i++) {
      LCD.DrawRectangle(5, 40 + (i * 40), 310, 35);
      LCD.WriteAt(programs[i]->getName(), 20, 50 + (i * 40));
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
      // Display the init button
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Init", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to initilize the program
      while (!LCD.Touch(&x, &y));
      // Initilize the program
      program->init();
      // Clear the screen and display the run button
      LCD.Clear(FEHLCD::Black);
      LCD.SetFontColor(FEHLCD::White);
      LCD.WriteLine(program->getName());
      LCD.DrawRectangle(5, 40, 310, 150);
      LCD.WriteAt("Run", 135, 72 + 40);
      Sleep(6);
      // Wait for user touch to run the program
      while (!LCD.Touch(&x, &y));
      // Run the program
      program->run();
    }
  }
}