#ifndef TASK_H
#define TASK_H

#include "Waypoint.h"
#include "Component.h"

/**
 * A task on the course.
 */
class Task: public Component {
  protected:
    /**
     * A reference to the task waypoint.
     */
    Waypoint* waypoint;
  public:
    /**
     * Construct a new Task object
     * 
     * @param waypoint A reference to the task waypoint.
     */
    Task(Waypoint* waypoint);
    /**
     * Get the reference to the waypoint.
     * 
     * @return Waypoint* 
     */
    Waypoint* getWaypoint();
    /**
     * Align the robot with the task.
     * This method should be implemented to preform more precise
     * alignment after the intial alignment with the task waypoint.
     * 
     * @return true The alignment was successful.
     * @return false The robot is still aligning.
     */
    virtual bool align() = 0;
    /**
     * Execute the task.
     * 
     * @return true The task is finished.
     * @return false The task is still executing.
     */
    virtual bool execute() = 0;
};

#endif