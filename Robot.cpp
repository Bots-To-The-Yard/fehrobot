#include "Robot.h"

Robot::Robot(Waypoint* waypoints): Module(), leftLight(FEHIO::P1_0), centerLight(FEHIO::P1_1), rightLight(FEHIO::P1_2), drivetrain() {
  this->waypoints = waypoints;
  target = -1;
  navEnabled = false;
  drivetrain = Drivetrain();
  lineState = NO_LINE;
  leftPercent = 0;
  rightPercent = 0;
}

Robot::Robot(
  Waypoint* waypoints,
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftMotorPort,
  FEHMotor::FEHMotorPort rightMotorPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin
): Module(),
 leftLight(leftPin),
 centerLight(centerPin),
 rightLight(rightPin),
 drivetrain(leftMotorPort, rightMotorPort, leftEncoderPin, rightEncoderPin)
{
  this->waypoints = waypoints;
  target = -1;
  navEnabled = false;
  drivetrain = Drivetrain();
  lineState = NO_LINE;
  leftPercent = 0;
  rightPercent = 0;
}

void Robot::init() {
  drivetrain.init();
  rps.init();
}

void Robot::stop() {
  drivetrain.stop();
  rps.stop();
  stopLineFollow();
}

void Robot::update(double time) {
  drivetrain.update(time);
  rps.update(time);
  updateLineFollow();
}

void Robot::updateLineFollow() {
  // Update the line state
  if (leftLight.Value() > LINE_VOLTAGE && centerLight.Value() > LINE_VOLTAGE && rightLight.Value() > LINE_VOLTAGE) {
    lineState = AT_LINE;
  } if (leftLight.Value() > LINE_VOLTAGE) {
    lineState = RIGHT_OF_LINE;
  } else if (rightLight.Value() > LINE_VOLTAGE) {
    lineState = LEFT_OF_LINE;
  } else if (centerLight.Value() > LINE_VOLTAGE) {
    lineState = ON_LINE;
  } else {
    lineState = NO_LINE;
  }
  // If line following is enabled, try to follow the line
  if (followLine) {
    switch (lineState) {
      case LEFT_OF_LINE:
        if (!rightPercent) {
          rightPercent = drivetrain.getRightPercent();
          drivetrain.setRightPercent(rightPercent * 0.75);
        }
        break;
      case RIGHT_OF_LINE:
        if (!leftPercent) {
          leftPercent = drivetrain.getLeftPercent();
          drivetrain.setLeftPercent(leftPercent * 0.75);
        }
        break;
      case ON_LINE:
        if (leftPercent) {
          drivetrain.setLeftPercent(leftPercent);
          leftPercent = 0;
        }
        if (rightPercent) {
          drivetrain.setRightPercent(rightPercent);
          rightPercent = 0;
        }
        break;
        default:
          // Stop the robot if the line is lost or it goes off course
          drivetrain.stop();
    }
  }
}

void Robot::telemetry() {
  drivetrain.telemetry();
  rps.telemetry();
}

void Robot::setTarget(int target) {
  this->target = target;
}

Waypoint* Robot::getTarget() {
  if (target == -1) return nullptr;
  return &waypoints[target];
}

void Robot::startNavigation() {
  navEnabled = true;
}

void Robot::stopNavigation() {
  navEnabled = false;
}

Drivetrain* Robot::getDrivetrain() {
  return &drivetrain;
}

RPSModule* Robot::getRPSModule() {
  return &rps;
}

bool Robot::startLineFollow() {
  // Only start following a line if the robot is actually on a line
  if (lineState != ON_LINE) {
    followLine = false;
  } else {
    followLine = true;
  }
  return followLine;
}

void Robot::stopLineFollow() {
  followLine = false;
}