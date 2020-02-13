#include "Waypoint.h"

Waypoint::Waypoint(bool upper, Bounds bounds, Heading heading, Surface surface, BumperState bumperState) {
  this->upper = upper;
  this->bounds = bounds;
  this->heading = heading;
  this->surface = surface;
  this->bumperState = bumperState;
}

Bounds Waypoint::getBounds() {
  return bounds;
}

Heading Waypoint::getHeading() {
  return heading;
}

Surface Waypoint::getSurface() {
  return surface;
}

BumperState Waypoint::getBumperState() {
  return bumperState;
}