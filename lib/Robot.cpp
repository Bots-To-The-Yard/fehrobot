#include "../include/Robot.h"

Robot::Robot(): Module(), drivetrain() {
  drivetrain = Drivetrain();
}

Robot::Robot(
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftMotorPort,
  FEHMotor::FEHMotorPort rightMotorPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin
): Module(),
 drivetrain(leftPin, centerPin, rightPin, leftMotorPort, rightMotorPort, leftEncoderPin, rightEncoderPin)
{
  drivetrain = Drivetrain();
}

void Robot::init() {
  drivetrain.init();
  // rps.init();
}

void Robot::stop() {
  drivetrain.stop();
  rps.stop();
}

void Robot::update(double time) {
  drivetrain.update(time);
  rps.update(time);
}

void Robot::telemetry() {
  drivetrain.telemetry();
  rps.telemetry();
}

void Robot::followLine() {
  followLine(DEFAULT_PERCENT);
}

void Robot::followLine(float percent) {
  switch (drivetrain.getLineState()) {
    case LEFT_OF_LINE:
      drivetrain.setRightPercent(0);
      break;
    case RIGHT_OF_LINE:
      drivetrain.setLeftPercent(0);
      break;
    case ON_LINE:
      drivetrain.setPercent(percent);
      break;
    default:
      break;
  }
}

bool Robot::followLine(float percent, float distance) {
  if (drivetrain.getAverageDistance() <= distance) {
    followLine(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::drive(float distance) {
  return drive(distance, DEFAULT_PERCENT);
}

bool Robot::drive(float distance, float percent) {
  if (drivetrain.getAverageDistance() <= distance) {
    drivetrain.setPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnLeft() {
  return turnLeft(DEFAULT_PERCENT);
}

bool Robot::turnLeft(float percent) {
  if (drivetrain.getAverageDistance() <= TURN_DISTANCE) {
    drivetrain.setLeftPercent(-percent);
    drivetrain.setRightPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnLeftDegree(float degree, float percent) {
   if (drivetrain.getAverageDistance() <= (degree / 90) * TURN_DISTANCE) {
    drivetrain.setLeftPercent(-percent);
    drivetrain.setRightPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnRight() {
  return turnLeft(DEFAULT_PERCENT);
}

bool Robot::turnRight(float percent) {
  if (drivetrain.getAverageDistance() <= TURN_DISTANCE) {
    drivetrain.setLeftPercent(percent);
    drivetrain.setRightPercent(-percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnRightDegree(float degree, float percent) {
    if (drivetrain.getAverageDistance() <= (degree / 90) * TURN_DISTANCE) {
    drivetrain.setLeftPercent(percent);
    drivetrain.setRightPercent(-percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

Drivetrain* Robot::getDrivetrain() {
  return &drivetrain;
}

RPSModule* Robot::getRPSModule() {
  return &rps;
}