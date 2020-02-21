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
     * The logger instance.
     */
    Logger* logger;
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
    virtual void loop() = 0;
  public:
    /**
     * Construct a new Program object
     * 
     * @param robot The program name.
     * @param robot A reference to the Robot.
     * @param course A reference to the Course.
     * @param logger A reference to the Logger.
     */
    Program(char* name, Robot* robot, Course* course, Logger* logger);
    /**
     * Get the program name
     * 
     * @return The program name
     */
    char* getName();
    /**
     * Initialize the program.
     */
    virtual void init();
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
    virtual void telemetry();
};

#endif