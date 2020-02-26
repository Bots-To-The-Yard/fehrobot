#include "../include/Course.h"

Course::Course(): Component() {
  waypoints = {};
  jukebox = Jukebox(nullptr);
}

void Course::init() {
  jukebox.init();
}

void Course::stop() {
  jukebox.stop();
}

void Course::telemetry() {
  jukebox.telemetry();
}

int Course::getTime() {
  return RPS.Time();
}

char Course::getRegion() {
  return RPS.CurrentRegionLetter();
}

char Course::getNumber() {
  return RPS.CurrentCourse();
}

Waypoint* Course::getWaypoint(int index) {
  return &waypoints[index];
}

Waypoint* Course::getWaypoints() {
  return waypoints;
}

Jukebox* Course::getJukebox() {
  return &jukebox;
}