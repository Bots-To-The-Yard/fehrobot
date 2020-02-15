#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "modules.h"

/**
 * The RPS bounding box for a Waypoint.
 */
struct Bounds {
  float minX;
  float maxX;
  float minY;
  float maxY;
};

/**
 * The CdS cell min and max intensity.
 */
struct Surface {
  float minIntensity;
  float maxIntensity;
};

/**
 * The state of the robot bumper microswitches.
 */
struct BumperState {
  bool frontLeft;
  bool frontRight;
  bool rearLeft;
  bool rearRight;
};

/**
 * A waypoint on the course.
 * Waypoints are used to navigate the robot to a 
 * specific position/alignment on the course.
 */
class Waypoint {
  private:
    /**
     * The Waypoint is above the ramp.
     */
    bool aboveRamp;
    /**
     * The RPS bounding box.
     */
    Bounds bounds;
    /**
     * The RPS heading constraint.
     */
    float heading;
    /**
     * The CdS cell surface.
     */
    Surface surface;
    /**
     * The robot bumper state.
     */
    BumperState bumperState;
    /**
     * The line detection state.
     */
    LineState lineState;
  public:
    /**
     * Construct a new Waypoint object
     * 
     * @param aboveRamp Is the Waypoint above the ramp.
     * @param bounds The RPS bounding box.
     * @param heading The RPS heading.
     * @param surface The CdS cell surface.
     * @param bumperState The robot bumper state.
     * @param lineState The optosensor line state.
     */
    Waypoint(bool aboveRamp, Bounds bounds, float heading, Surface surface, BumperState bumperState, LineState lineState);
    /**
     * Get the Above Ramp object
     * 
     * @return true The waypoint is above the ramp.
     * @return false The waypoint is below the ramp.
     */
    bool getAboveRamp();
    /**
     * Get the RPS bounds.
     * 
     * @return The Bounds.
     */
    Bounds getBounds();
    /**
     * Get the RPS heading constraint.
     * 
     * @return The heading.
     */
    float getHeading();
    /**
     * Get the CdS cell surface.
     * 
     * @return The Surface.
     */
    Surface getSurface();
    /**
     * Get the BumperState.
     * 
     * @return The BumperState.
     */
    BumperState getBumperState();
    /**
     * Get the LineState.
     * 
     * @return The LineState.
     */
    LineState getLineState();
};

#endif