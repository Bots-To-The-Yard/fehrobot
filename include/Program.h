#ifndef PROGRAM_H
#define PROGRAM_H

#include "Component.h"
#include "Robot.h"
#include "Course.h"

/**
 * A program.
 */
class Program: public Component {
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
     */
    Program(char* name);
    /**
     * Set the the pointer to the Robot object.
     * 
     * @param robot The Robot pointer.
     */
    void setRobot(Robot* robot);
    /**
     * Set the the pointer to the Course object.
     * 
     * @param course The Course pointer.
     */
    void setCourse(Course* course);
    /**
     * Set the the pointer to the Logger object.
     * 
     * @param logger The Logger pointer.
     */
    void setLogger(Logger* logger);
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
     * Stop the program.
     */
    void stop();
    /**
     * Print program telemetry information to the screen.
     */
    virtual void telemetry();
    /**
     * Updates the program and other components.
     * This is the root function that calls the update on all other functions.
     * 
     * @param time The time since the program started.
     */
    void update(double time);
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
};

#endif