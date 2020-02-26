#include "Performance02.h"
#include <FEHUtility.h>
using namespace program;

Performance02::Performance02(): Program("Performance 2") {
  state = -1;
}

void Performance02::init() {
  Program::init();
  logger->debug("Performance02::init", "Set state to 0");
  // Reset the state to 0
  state = -1;
}

void Performance02::telemetry() {
  Program::telemetry();
  logger->telemetry("Program State: %d", state);
}

void Performance02::loop() {
  switch (state) {
    case -1:
      if (robot->getDrivetrain()->getCdsColor() != None) {
        state = 0;
      }
      break;
    case 0:
      // Drive towards the ramp
      if (robot->drive(10, -25)) {
        state = 1;
      }
      break;
    case 1:
      // Turn towards the ramp
      if (robot->turnLeft(135, 25)) {
        state = 2;
      }
      break;
    case 2:
       // Drive up the ramp
       if (robot->drive(32, 40)) {
         state = 3;
       }
      break;
    case 3:
      // turn towards the wall
      if (robot->turnLeftWide(90, 30)) {
        state = 4;
      }
      break;
    case 4:
      // turn towards the wall
      if (robot->drive(1.25)) {
        state = 5;
      }
      break;
    case 5:
      // turn towards the wall
      if (robot->turnLeftWide(90, 30)) {
        state = 6;
      }
      break;
    case 6:
      // Drive towards the wall adjacent to the sink
      if (robot->drive(1.25, 40)) {
        state = 7;
      }
      break;
    case 7:
      // back up from the sink
      if (robot->drive(6, -40)) {
        state = 8;
      }
      break;
    // case 6:
    //   // turn arm towards sink
    //   if (robot->turnLeft()) {
    //     state = 7;
    //   }
    //   break;
    // case 7:
    //   // slam into sink
    //   if (robot->drive(6, 40)) {
    //     state = 8;
    //   }
    //   break;
    // case 8:
    //   // slam into sink
    //   if (robot->drive(6, 40)) {
    //     state = 9;
    //   }
    //   break;
    // case 9:
    //   // back away from sink
    //   if (robot->drive(6, -40)) {
    //     state = 10;
    //   }
    //   break;
    // case 10:
    //   // turn back towards right side of course
    //   if (robot->turnLeft()) {
    //     state = 11;
    //   }
    //   break;
    // case 11:
    //   // turn drive in ramp direction
    //   if (robot->drive(10, 40)) {
    //     state = 12;
    //   }
    //   break;
    // case 12:
    //   // turn to go back down the ramp
    //   if (robot->turnRight()) {
    //     state = 13;
    //   }
    //   break;
    // case 13:
    //   // turn to go back down the ramp
    //   if (robot->drive(20, 40)) {
    //     state = 14;
    //   }
    //   break;
    // case 14:
    //   // turn to right side of course
    //   if (robot->turnLeft()) {
    //     state = 15;
    //   }
    //   break;
    // case 15:
    //   // hit the right wall
    //   if (robot->drive(20, 40)) {
    //     state = 16;
    //   }
    //   break;
    // case 16:
    //   // backing away from the wall
    //   if (robot->drive(6, -40)) {
    //     state = 17;
    //   }
    //   break;
    // case 17:
    //   // turn backwards to back towards the ticket
    //   if (robot->drive(6, -40)) {
    //     state = 18;
    //   }
    //   break;
    // case 18:
    //   // turn backwards
    //   if (robot->turnRight()) {
    //     state = 19;
    //   }
    //   break;
    // case 19:
    //   // angle to move towards the wall
    //   if (robot->turnRight(45)) {
    //     state = 20;
    //   }
    //   break;
    // case 20:
    //   // angle to move towards the wall
    //   if (robot->turnRight(45)) {
    //     state = 21;
    //   }
    //   break;
    default:
      stop();
      break;
  }
}