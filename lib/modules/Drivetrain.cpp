#include "../include/modules/Drivetrain.h"
#include "FEHLCD.h"
using namespace module;

Drivetrain::Drivetrain(): Module(), leftOpto(FEHIO::P1_0), centerOpto(FEHIO::P1_1), rightOpto(FEHIO::P1_2), left(FEHMotor::Motor0, 9.0), right(FEHMotor::Motor1, 9.0), leftEncoder(FEHIO::P0_0), rightEncoder(FEHIO::P0_1), cdsCell(FEHIO::P2_1) {
  lineState = NoLine;
}

Drivetrain::Drivetrain(
  FEHIO::FEHIOPin leftPin,
  FEHIO::FEHIOPin centerPin,
  FEHIO::FEHIOPin rightPin,
  FEHMotor::FEHMotorPort leftPort,
  FEHMotor::FEHMotorPort rightPort,
  FEHIO::FEHIOPin leftEncoderPin,
  FEHIO::FEHIOPin rightEncoderPin,
  FEHIO::FEHIOPin cdsCellPin
): 
  Module(), 
  leftOpto(leftPin),
  centerOpto(centerPin),
  rightOpto(rightPin), 
  left(leftPort, 9.0), 
  right(rightPort, 9.0), 
  leftEncoder(leftEncoderPin), 
  rightEncoder(rightEncoderPin),
  cdsCell(cdsCellPin)
{
  this->logFile = logFile;
  lineState = NoLine;
}

void Drivetrain::init() {
  resetEncoders();
}

void Drivetrain::update(double time) {
  // Update the line state
  if (leftOpto.Value() > LEFT_VOLTAGE && centerOpto.Value() > CENTER_VOLTAGE && rightOpto.Value() > RIGHT_VOLTAGE) {
    lineState = AtLine;
  } else if (leftOpto.Value() > LEFT_VOLTAGE) {
    lineState = RightOfLine;
  } else if (rightOpto.Value() > RIGHT_VOLTAGE) {
    lineState = LeftOfLine;
  } else if (centerOpto.Value() > CENTER_VOLTAGE) {
    lineState = OnLine;
  } else {
    lineState = NoLine;
  }
}

void Drivetrain::telemetry() {
  // TODO: Print current encoder counts to screen
  switch (lineState) {
    case OnLine: {
      LCD.WriteLine("Line State: ON LINE");
      break;
    }
    case LeftOfLine: {
      LCD.WriteLine("Line State: LEFT OF LINE");
      break;
    };
    case RightOfLine: {
      LCD.WriteLine("Line State: RIGHT OF LINE");
      break;
    };
    case AtLine: {
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
  LCD.WriteLine("CDS Color: ");
  LCD.WriteLine(cdsCell.Value());
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

CdsColor Drivetrain::getCdsColor() {
  // TODO: Implement CdS color detection
  return None;
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
