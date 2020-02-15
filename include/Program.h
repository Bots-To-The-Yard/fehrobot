#ifndef PROGRAM_H
#define PROGRAM_H

#include "Component.h"
#include "Robot.h"

/**
 * A basic robot program.
 */
class Program: public Component {
  private:
    /**
     * A reference to the Robot object.
     */
    Robot* robot;
  public:
    /**
     * Construct a new Program object
     * 
     * @param robot A reference to the Robot object.
     */
    Program(Robot* robot);
    /**
     * The main loop method.
     */
    virtual void loop() = 0;
    void init();
    void stop();
    void update(double time);
    void telemetry();
};

#endif