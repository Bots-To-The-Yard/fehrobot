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
      if (robot->turnRightWide()) {
        Sleep(2.0);
        state = 1;
      }
      break;
    case 1:
      if (robot->turnLeftWide()) {
        Sleep(2.0);
        state = 2;
      }
      break;
    case 2:
      if (robot->turnRightWide(45)) {
        Sleep(2.0);
        state = 3;
      }
      break;
    case 3:
      if (robot->turnLeftWide(45)) {
        Sleep(2.0);
        state = 4;
      }
      break;
    case 4:
      if (robot->turnRightWide(135)) {
        state = 5;
      }
      break;
    case 5:
      if (robot->turnLeftWide(135)) {
        state = 6;
      }
      break;
    default:
      stop();
      break;
  }
}