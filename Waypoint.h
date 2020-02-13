#ifndef WAYPOINT_H
#define WAYPOINT_H

struct Bounds {
  float minX;
  float maxX;
  float minY;
  float maxY;
};

struct Heading {
  float min;
  float max;
};

struct Surface {
  float minIntensity;
  float maxIntensity;
};

struct BumperState {
  bool frontLeft;
  bool frontRight;
  bool rearLeft;
  bool rearRight;
};

class Waypoint {
  private:
    bool upper;
    Bounds bounds;
    Heading heading;
    Surface surface;
    BumperState bumperState;
  public:
    Waypoint(bool upper, Bounds bounds, Heading heading, Surface surface, BumperState bumperState);
    bool isUpper();
    Bounds getBounds();
    Heading getHeading();
    Surface getSurface();
    BumperState getBumperState();
};

#endif