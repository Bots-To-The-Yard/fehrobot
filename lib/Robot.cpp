#include "../include/Robot.h"

Robot::Robot(Logger* logger): Module(logger), drivetrain(logger), rps(logger) {
  this->logger = logger;
}

Robot::Robot(
  Logger* logger,
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftMotorPort,
  FEHMotor::FEHMotorPort rightMotorPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin,
  FEHIO::FEHIOPin cdsCellPin
): Module(logger), drivetrain(logger, leftPin, centerPin, rightPin, leftMotorPort, rightMotorPort, leftEncoderPin, rightEncoderPin, cdsCellPin), rps(logger) {
}

void Robot::init() {
  // Initilize with RPS enabled by default
  init(true);
}

void Robot::init(bool enableRps) {
  drivetrain.init();
  if (enableRps) rps.init();
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
    case LeftOfLine:
      drivetrain.setRightPercent(0);
      break;
    case RightOfLine:
      drivetrain.setLeftPercent(0);
      break;
    case OnLine:
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