#include "DriveForward.h"
using namespace program;

DriveForward::DriveForward(): Program("Turn Right") {
  state = 0;
}

void DriveForward::init() {
  Program::init();
  // Reset the state to 0
  state = 0;
}

void DriveForward::loop() {
  switch (state) {
    case 0:
      if (robot->turnRight())
        state = 1;
      break;
    default:
      stop();
      break;
  }
}