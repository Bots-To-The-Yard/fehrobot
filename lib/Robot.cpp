#include "../include/Robot.h"
#include <FEHBattery.h>

Robot::Robot(Logger* logger): Module(logger), drivetrain(logger), rps(logger) {
  sleepStart = 0;
  sleeping = false;
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
  sleepStart = 0;
  sleeping = false;
}

void Robot::init() {
  logger->debug("Robot::init", "Initialize Robot");
  logger->info("Robot::init", "Battery Voltage: %4.2f", Battery.Voltage());
  // rps.init();
  drivetrain.init();
}

void Robot::stop() {
  drivetrain.stop();
  rps.stop();
}

void Robot::update(double time) {
  drivetrain.update(time);
  rps.update(time);
  // Update sleep function
  this->time = time;
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
  return turnLeft(90, DEFAULT_PERCENT);
}

bool Robot::turnLeft(float angle) {
  return turnLeft(angle, DEFAULT_PERCENT);
}

bool Robot::turnLeft(float angle, float percent) {
   if (drivetrain.getAverageDistance() <= (angle / 90) * TURN_DISTANCE) {
    drivetrain.setLeftPercent(-percent);
    drivetrain.setRightPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnLeftWide() {
  return turnLeftWide(90, DEFAULT_PERCENT);
}

bool Robot::turnLeftWide(float angle) {
  return turnLeftWide(angle, DEFAULT_PERCENT);
}

bool Robot::turnLeftWide(float angle, float percent) {
  if (drivetrain.getRightDistance() <= (angle / 90) * (TURN_DISTANCE * 2)) {
    drivetrain.setRightPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnRight() {
  return turnRight(90, DEFAULT_PERCENT);
}

bool Robot::turnRight(float angle) {
  return turnRight(angle, DEFAULT_PERCENT);
}

bool Robot::turnRight(float angle, float percent) {
  if (drivetrain.getAverageDistance() <= (angle / 90) * TURN_DISTANCE) {
    drivetrain.setLeftPercent(percent);
    drivetrain.setRightPercent(-percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::turnRightWide() {
  return turnRightWide(90, DEFAULT_PERCENT);
}

bool Robot::turnRightWide(float angle) {
  return turnRightWide(angle, DEFAULT_PERCENT);
}

bool Robot::turnRightWide(float angle, float percent) {
  if (drivetrain.getLeftDistance() <= (angle / 90) * (TURN_DISTANCE * 2)) {
    drivetrain.setLeftPercent(percent);
    return false;
  } else {
    drivetrain.stop();
    return true;
  }
}

bool Robot::sleep(double seconds) {
  if (!sleeping) {
    sleepStart = time;
    sleeping = true;
  } else {
    if ((time - sleepStart) >= seconds) {
      sleepStart = 0;
      sleeping = false;
    }
  }
  return !sleeping;
}

Drivetrain* Robot::getDrivetrain() {
  return &drivetrain;
}

RPSModule* Robot::getRPSModule() {
  return &rps;
}