#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Program.h"
using namespace std;

/**
 * The program selection menu.
 */
class Menu {
  private:
    /**
     * The a pointer to the Logger object.
     */
    Logger* logger;
    /**
     * A pointer to the Robot object.
     */
    Robot* robot;
    /**
     * A pointer to the Course object.
     */
    Course* course;
    /**
     * The programs to display.
     */
    vector<Program*> programs;
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
  public:
    /**
     * Construct a new Menu object
     */
    Menu();
    /**
     * Construct a new Menu object
     * 
     * @param robot A pointer to the robot.
     * @param course A pointer to the course.
     * @param logger A pointer to the logger.
     */
    Menu(Robot* robot, Course* course, Logger* logger);
    /**
     * Add a program to the menu.
     * 
     * @param program A pointer to the program.
     */
    void addProgram(Program* program);
    /**
     * Display the program selection menu.
     */
    void display();
};

#endif