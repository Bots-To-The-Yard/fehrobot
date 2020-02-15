#include "../include/Task.h"

Task::Task(Waypoint* waypoint) {
  this->waypoint = waypoint;
}

Waypoint* Task::getWaypoint() {
  return waypoint;
}