#ifndef MENU_H
#define MENU_H

#include "Program.h"

/**
 * The program selection menu.
 */
class Menu {
  private:
    /**
     * The logger instance.
     */
    Logger* logger;
    /**
     * The programs to display.
     */
    Program** programs;
    /**
     * The active program.
     */
    Program* program;
    /**
     * The x touch coordinate.
     */
    float x;
    /**
     * The y touch coordinate.
     */
    float y;
    /**
     * The number of programs to display.
     */
    int programCount;
  public:
    /**
     * Construct a new Menu object
     */
    Menu();
    /**
     * Construct a new Menu object
     * 
     * @param programs The programs to display.
     * @param programCount The number of programs to display.
     * @param logger A reference to the logger.
     */
    Menu(Program** programs, int programCount, Logger* logger);
    /**
     * Display the program selection menu.
     */
    void display();
};

#endif