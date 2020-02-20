#include "DriveForward.h"
using namespace program;

DriveForward::DriveForward(Robot* robot, Course* course): Program("Forward Up Ramp", robot, course) {
  state = 0;
}

void DriveForward::init() {
  Program::init(false);
  // Reset the state to 0
  state = 0;
}

void DriveForward::loop() {
  switch (state) {
    case 0:
      if (robot->drive(15, 10))
        state = 1;
      break;
    default:
      stop();
      break;
  }
}