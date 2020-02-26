#ifndef COURSE_H
#define COURSE_H

#include "FEHRPS.h"
#include "Waypoint.h"
#include "Component.h"
#include "tasks.h"
using namespace task;

/**
 * The robot course.
 */
class Course: public Component {
  private:
    /**
     * The course waypoints.
     */
    Waypoint* waypoints;
    /**
     * The Jukebox task.
     */
    Jukebox jukebox;
  public:
    /**
     * Constructs a course.
     */
    Course();
    void init();
    void stop();
    void telemetry();
    /**
     * Gets the time left from RPS.
     * 
     * @return The time remaining.
     */
    int getTime();
    /**
     * Gets the course region letter.
     * 
     * @returns The current course region.
     */
    char getRegion();
    /**
     * Gets the course number.
     * 
     * @returns The current course number.
     */
    char getNumber();
    /**
     * Gets all the course waypoints.
     * 
     * @returns The course waypoints.
     */
    Waypoint* getWaypoints();
    /**
     * Gets a specific course waypoint.
     * 
     * @param index The index of the waypoint.
     * @return The way point or nullptr if not found.
     */
    Waypoint* getWaypoint(int index);
    /**
     * Gets the Jukebox task.
     * 
     * @return A reference to the Jukebox task.
     */
    Jukebox* getJukebox();
};

#endif