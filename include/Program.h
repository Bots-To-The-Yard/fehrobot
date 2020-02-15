#ifndef PROGRAM_H
#define PROGRAM_H

#include "Component.h"
#include "Robot.h"
#include "Course.h"

/**
 * A program.
 */
class Program {
  private:
    /**
     * The program name.
     */
    char* name;
    /**
     * Is the program running.
     */
    bool running;
  protected:
    /**
     * A reference to the Robot object.
     */
    Robot* robot;
    /**
     * A reference to the Course object.
     */
    Course* course;
    /**
     * The time when the program started
     */
    float startTime;
    /**
     * The last time the telemetry was printed.
     */
    float lastTelemetry;
    /**
     * The main loop method.
     */
    virtual void loop();
  public:
    /**
     * Construct a new Program object
     * 
     * @param robot The program name.
     */
    Program(char* name, Robot* robot, Course* course);
    /**
     * Get the program name
     * 
     * @return The program name
     */
    char* getName();
    /**
     * Initilize the program.
     */
    void init();
    /**
     * Run the program.
     * 
     * @param robot A reference to the Robot object.
     * @param course A reference to the Course object.
     */
    void run();
    /** 
     * Run the program.
     * 
     * @param robot A reference to the Robot object.
     * @param course A reference to the Course object.
     * @param telemetry Enable/disable telemetry.
     */
    void run(bool telemetry);
    /**
     * Stop the program.
     */
    void stop();
};

#endif