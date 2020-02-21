#ifndef COMPONENT_H
#define COMPONENT_H

/**
 * A standard robot/course component.
 */
class Component {
  public:
    /**
     * Initialize the component.
     * 
     * This method is run to preform any initilization tasks before the control loop.
     */
    virtual void init() = 0;
    /**
     * Stop the component.
     * 
     * Running this method should immediatly stop any mechanical components or the task execution.
     */ 
    virtual void stop() = 0;
    /**
     * Print telemetry information to the screen.
     */
    virtual void telemetry() = 0;
    /**
     * Update the component with the current time.
     * This method should be run each time the control loop runs.
     * 
     * @param time The time since the program/segment started.
     */
    virtual void update(double time) = 0;
};

#endif