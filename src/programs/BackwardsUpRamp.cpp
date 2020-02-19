#include "BackwardsUpRamp.h"
using namespace program;

BackwardsUpRamp::BackwardsUpRamp(Robot* robot, Course* course): Program("Backwards Up Ramp", robot, course) {
  state = 0;
}

void BackwardsUpRamp::init() {
  Program::init();
  // Reset the state to 0
  state = 0;
}

void BackwardsUpRamp::loop() {
  switch (state) {
    case 0:
      if (robot->drive(40, -60))
        state = 1;
      break;
    default:
      stop();
      break;
  }
}