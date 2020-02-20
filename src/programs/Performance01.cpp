#include "Performance01.h"
using namespace program;

Performance01::Performance01(Robot* robot, Course* course): Program("Performance 1", robot, course) {
  state = 0;
}

void Performance01::init() {
  Program::init();
  // Reset the state to 0
  state = 0;
}

void Performance01::loop() {
  switch (state) {
    case 0:
      if (robot->drive(12, 40))
        state = 1;
      break;
    case 1:
      if (robot->turnLeftDegree(45, 40))
        state = 2;
      break;
    case 2:
      if (robot->drive(23, 60))
        state = 3;
      break;
    case 3:
      if (robot->drive(23, -15))
        state = 4;
      break;
    case 4:
      if (robot->turnLeftDegree(90, 40))
        state = 5;
      break;
    case 5:
      if (robot->drive(9, 40))//driving to line
        state = 6;
      break;
    default:
      stop();
      break;
      state = 0;
  }
}