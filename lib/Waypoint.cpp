#include "../include/Waypoint.h"

Waypoint::Waypoint(bool aboveRamp, Bounds bounds, float heading, Surface surface, BumperState bumperState, LineState lineState) {
  this->aboveRamp = aboveRamp;
  this->bounds = bounds;
  this->heading = heading;
  this->surface = surface;
  this->bumperState = bumperState;
  this->lineState = lineState;
}

bool Waypoint::getAboveRamp() {
  return aboveRamp;
}

Bounds Waypoint::getBounds() {
  return bounds;
}

float Waypoint::getHeading() {
  return heading;
}

Surface Waypoint::getSurface() {
  return surface;
}

BumperState Waypoint::getBumperState() {
  return bumperState;
}