#include "Drivetrain.h"

Drivetrain::Drivetrain(): Module(), left(FEHMotor::Motor0, 9.0), right(FEHMotor::Motor1, 9.0), leftEncoder(FEHIO::P0_0), rightEncoder(FEHIO::P0_1) {}

Drivetrain::Drivetrain(FEHMotor::FEHMotorPort leftPort, FEHMotor::FEHMotorPort rightPort, FEHIO::FEHIOPin leftEncoderPin, FEHIO::FEHIOPin rightEncoderPin): Module(), left(leftPort, 9.0), right(rightPort, 9.0), leftEncoder(leftEncoderPin), rightEncoder(rightEncoderPin) {}

void Drivetrain::init() {
  resetCounts();
}

void Drivetrain::update(double time) {
  if (leftTargetDistance != 0) {
    if (getLeftDistance() >= leftTargetDistance) {
      left.SetPercent(0);
      leftTargetDistance = 0;
    } else if (maxLeftPercent && minLeftPercent && getLeftDistance() <= accelDistance) {
      // Acceleration
      left.SetPercent(((getLeftDistance() / accelDistance) * (maxLeftPercent - minLeftPercent)) + minLeftPercent);
    } else if (maxLeftPercent && minLeftPercent && getLeftDistance() >= (leftTargetDistance - accelDistance)) {
      // Deceleration
      left.SetPercent((((leftTargetDistance - getLeftDistance()) / accelDistance) * (maxLeftPercent - minLeftPercent)) + minLeftPercent);
    } else {
      left.SetPercent(maxLeftPercent);
    }
  } else {
    left.SetPercent(maxLeftPercent);
  }
  if (rightTargetDistance != 0) {
    if (getRightDistance() >= rightTargetDistance) {
      right.SetPercent(0);
      rightTargetDistance = 0;
    } else if (maxRightPercent && minRightPercent && getRightDistance() <= accelDistance) {
      // Acceleration
      right.SetPercent(((getRightDistance() / accelDistance) * (maxRightPercent - minRightPercent)) + minRightPercent);
    } else if (maxRightPercent && minRightPercent && getRightDistance() >= (rightTargetDistance - accelDistance)) {
      // Deceleration
      right.SetPercent((((rightTargetDistance - getRightDistance()) / accelDistance) * (maxRightPercent - minRightPercent)) + minRightPercent);
    } else {
      right.SetPercent(maxRightPercent);
    }
  } else {
    right.SetPercent(maxRightPercent);
  }
}

void Drivetrain::telemetry() {
  // TODO: Print current encoder counts to screen
}

void Drivetrain::stop() {
  left.Stop();
  right.Stop();
  setPercent(0);
}

void Drivetrain::setAccelDistance(float accelDistnace) {
  this->accelDistance = accelDistance;
}

void Drivetrain::setMinLeftPercent(float percent) {
  minLeftPercent = percent;
}

void Drivetrain::setMinRightPercent(float percent) {
  minRightPercent = percent;
}

void Drivetrain::setPercent(float percent) {
  maxLeftPercent = percent;
  maxRightPercent = percent;
}

void Drivetrain::setLeftPercent(float percent) {
  maxLeftPercent = percent;
}


void Drivetrain::setRightPercent(float percent) {
  maxRightPercent = percent;
}

float Drivetrain::getLeftPercent() {
  return maxLeftPercent;
}

float Drivetrain::getRightPercent() {
  return maxRightPercent;
}

int Drivetrain::getLeftCounts() {
  return leftEncoder.Counts();
}


int Drivetrain::getRightCounts() {
  return rightEncoder.Counts();
}

void Drivetrain::resetLeftCounts() {
  leftEncoder.ResetCounts();
}

void Drivetrain::resetRightCounts() {
  rightEncoder.ResetCounts();
}

void Drivetrain::resetCounts() {
  leftEncoder.ResetCounts();
  rightEncoder.ResetCounts();
}

int Drivetrain::getCountDelta() {
  int delta = getLeftCounts() - getRightCounts();
  if (delta < 0) {
    return -1 * delta;
  } else {
    return delta;
  }
}

float Drivetrain::getLeftDistance() {
  return CIRCUMFERENCE * (getLeftCounts() / COUNTS_PER_ROTATION);
}

float Drivetrain::getRightDistance() {
  return CIRCUMFERENCE * (getRightCounts() / COUNTS_PER_ROTATION);
}

float Drivetrain::getAverageDistance() {
  return (getLeftDistance() + getRightDistance()) / 2;
}

void Drivetrain::resetLeftDistance() {
  resetLeftCounts();
}

void Drivetrain::resetRightDistance() {
  resetRightCounts();
}

void Drivetrain::setTargetDistance(float targetDistance) {
  this->leftTargetDistance = targetDistance;
  this->rightTargetDistance = targetDistance;
}

void Drivetrain::setLeftTargetDistance(float targetDistance) {
  this->leftTargetDistance = targetDistance;
}

void Drivetrain::setRightTargetDistance(float targetDistance) {
  this->rightTargetDistance = targetDistance;
}