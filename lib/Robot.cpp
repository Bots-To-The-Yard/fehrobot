#include "../include/Robot.h"
#include <FEHBattery.h>

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
  logger->debug("Initialize Robot");
  logger->info("Battery Voltage: %4.2f", Battery.Voltage());
  // rps.init();
  drivetrain.init();
}

void Robot::stop() {
  logger->debug("Stop Robot");
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

bool Robot::driveUntilLine(float percent, float maxDistance) {
  if (drivetrain.getAverageDistance() <= maxDistance) {
    return driveUntilLine(percent);
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::driveUntilLine(float percent) {
  if (drivetrain.getLineState() != NoLine) {
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
  return turnRight(DEFAULT_PERCENT);
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