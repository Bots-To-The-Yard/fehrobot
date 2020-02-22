#include "Performance01.h"
#include <FEHUtility.h>
using namespace program;

Performance01::Performance01(): Program("Performance 1") {
  state = -1;
}

void Performance01::init() {
  Program::init();
  logger->debug("Set state to 0");
  // Reset the state to 0
  state = -1;
}

void Performance01::telemetry() {
  Program::telemetry();
  logger->telemetry("Program State: %d", state);
}

void Performance01::loop() {
  switch (state) {
    case -1:
      if (robot->getDrivetrain()->getCdsColor() != None) {
        state = 0;
      }
      break;
    case 0:
      // Drive towards the ramp
      if (robot->drive(10, -25)) {
        if (robot->sleep(1.0)) state = 1;
      }
      break;
    case 1:
      // Turn towards the ramp
      if (robot->turnLeftDegree(130, 15)) {
        if (robot->sleep(1.0)) state = 2;
      }
      break;
    case 2:
      // Drive up the ramp
      if (robot->drive(20, 40)) {
        if (robot->sleep(3.0)) state = 3;
      }
      break;
    case 3:
      // Back down ramp
      if (robot->drive(20, -25)) {
        if (robot->sleep(2.0)) state = 3;
      }
      break;
    case 4:
      // Turn left towards the wall
      if (robot->turnLeft(15)) {
        if (robot->sleep(1.0)) state = 3;
      }
      break;
    case 5:
      // Drive towards wall
      if (robot->drive(8.5)) {
        if (robot->sleep(1.0)) state = 3;
      }
      break;
    case 6:
      // Back up from wall
      if (robot->drive(2.3, -15)) {
        if (robot->sleep(1.0)) state = 3;
      }
      break;
    case 7:
      // Turn towards jukebox
      if (robot->turnLeftDegree(80,20)) {
        if (robot->sleep(1.0)) state = 3;
      }
      break;
    case 8:
      // Drive towards light
      if (robot->drive(2, -15)) {
        robot->stop();
        state = 9;
      }
      break;
    case 9:
      // Drive to light
      if (robot->getDrivetrain()->getAverageDistance() <= 6) {
        robot->getDrivetrain()->setPercent(10);
        // If we see red, hit the red button
        if (robot->getDrivetrain()->getCdsColor() == Red) {
          if (robot->sleep(2.0)) state = 11;
        }
      } else {
        // Assume it's blue
        robot->stop();
        state = 12;
      }
      break;
    case 10:
      // Drive to light
      /*if (robot->getDrivetrain()->getAverageDistance() <= 3) {
        robot->getDrivetrain()->setPercent(-10);
        if (robot->getDrivetrain()->getCdsColor() == Red) {
          state = 11;
        } else if (robot->getDrivetrain()->getCdsColor() == Blue) {
          state = 12;
        }
      } else {
        robot->stop();
        state = 9;
      }*/
      break;
    case 11:
      if (robot->turnRightDegree(15, 20)) {
        if (robot->sleep(2.0)) state = 13;
      }
      break;
    case 12:
      if (robot->turnLeftDegree(15, 20)) {
        if (robot->sleep(2.0)) state = 13;
      }
      break;
    case 13:
      if (robot->drive(10, 60)) state = 14;
      break;
    case 14:
      if (robot->drive(-4, 60)) state = 15;
      break;
    default:
      stop();
      break;
  }
}