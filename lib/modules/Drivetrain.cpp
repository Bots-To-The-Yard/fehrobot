#include "../include/modules/Drivetrain.h"
#include "FEHLCD.h"
using namespace module;

Drivetrain::Drivetrain(): Module(), leftLight(FEHIO::P1_0), centerLight(FEHIO::P1_1), rightLight(FEHIO::P1_2), left(FEHMotor::Motor0, 9.0), right(FEHMotor::Motor1, 9.0), leftEncoder(FEHIO::P0_0), rightEncoder(FEHIO::P0_1) {
  lineState = NO_LINE;
}

Drivetrain::Drivetrain(
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftPort,
  FEHMotor::FEHMotorPort rightPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin
): Module(), leftLight(leftPin),
 centerLight(centerPin),
 rightLight(rightPin), 
 left(leftPort, 9.0), 
 right(rightPort, 9.0), 
 leftEncoder(leftEncoderPin), 
 rightEncoder(rightEncoderPin) 
 {
  lineState = NO_LINE;
}

void Drivetrain::init() {
  resetEncoders();
}

void Drivetrain::update(double time) {
  // Update the line state
  if (leftLight.Value() > LEFT_VOLTAGE && centerLight.Value() > CENTER_VOLTAGE && rightLight.Value() > RIGHT_VOLTAGE) {
    lineState = AT_LINE;
  } else if (leftLight.Value() > LEFT_VOLTAGE) {
    lineState = RIGHT_OF_LINE;
  } else if (rightLight.Value() > RIGHT_VOLTAGE) {
    lineState = LEFT_OF_LINE;
  } else if (centerLight.Value() > CENTER_VOLTAGE) {
    lineState = ON_LINE;
  } else {
    lineState = NO_LINE;
  }
}

void Drivetrain::telemetry() {
  // TODO: Print current encoder counts to screen
  switch (lineState) {
    case ON_LINE: {
      LCD.WriteLine("Line State: ON LINE");
      break;
    }
    case LEFT_OF_LINE: {
      LCD.WriteLine("Line State: LEFT OF LINE");
      break;
    };
    case RIGHT_OF_LINE: {
      LCD.WriteLine("Line State: RIGHT OF LINE");
      break;
    };
    case AT_LINE: {
      LCD.WriteLine("Line State: AT LINE");
      break;
    };
    default: {
      LCD.WriteLine("Line State: NO LINE");
    }
  }
  LCD.WriteLine("Left Counts:");
  LCD.WriteLine(getLeftCounts());
  LCD.WriteLine("Right Counts:");
  LCD.WriteLine(getRightCounts());
}

void Drivetrain::stop() {
  setPercent(0);
  resetEncoders();
}

void Drivetrain::setPercent(float percent) {
  left.SetPercent(percent);
  right.SetPercent(percent);
}

void Drivetrain::setLeftPercent(float percent) {
  left.SetPercent(percent);
}


void Drivetrain::setRightPercent(float percent) {
  right.SetPercent(percent);
}

LineState Drivetrain::getLineState() {
  return lineState;
}

int Drivetrain::getLeftCounts() {
  return leftEncoder.Counts();
}

int Drivetrain::getRightCounts() {
  return rightEncoder.Counts();
}

int Drivetrain::getAverageCounts() {
  return (rightEncoder.Counts() + leftEncoder.Counts()) / 2;
}

void Drivetrain::resetLeftEncoder() {
  leftEncoder.ResetCounts();
}

void Drivetrain::resetRightEncoder() {
  rightEncoder.ResetCounts();
}

void Drivetrain::resetEncoders() {
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
  return (PI * WHEEL_CIRCUMFERENCE * getLeftCounts()) / COUNTS_PER_ROTATION;
}

float Drivetrain::getRightDistance() {
  return (PI * WHEEL_CIRCUMFERENCE * getRightCounts()) / COUNTS_PER_ROTATION;
}

float Drivetrain::getAverageDistance() {
  return (getLeftDistance() + getRightDistance()) / 2;
}
