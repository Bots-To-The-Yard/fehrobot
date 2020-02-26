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
      if (robot->drive(5)) {
        Sleep(1.0);
        state = 1;
      }
      break;
    case 1:
      if (robot->turnRight()) {
        Sleep(2.0);
        state = 2;
      }
      break;
    case 2:
      if (robot->drive(5)) {
        state = 3;
      }
      break;
    case 3:
      if (robot->turnLeft()) {
        state = 4;
      }
      break;
    default:
      stop();
      break;
  }
}