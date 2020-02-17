#include "Exploration02.h"
using namespace program;

Exploration02::Exploration02(Robot* robot, Course* course): Program("Exploration 2", robot, course) {
  state = 0;
}

void Exploration02::init() {
  Program::init();
  // Reset the state to 0
  state = 0;
}

void Exploration02::loop() {
  switch (state) {
    case 0:
      if (robot->drive(14, 40))
        state = 1;
      break;
    case 1:
      if (robot->turnLeft(40))
        state = 2;
      break;
    case 2:
      if (robot->drive(10, 40))
        state = 3;
      break;
    case 3:
      if (robot->turnRight(60))
        state = 4;
      break;
    case 4:
      if (robot->drive(4, 60))
        state = 5;
      break;
    default:
      stop();
      break;
  }
}